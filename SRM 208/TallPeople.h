// TallPeople - SRM 208 Div 1 (1st problem)
// Full problem statement: https://community.topcoder.com/stat?c=problem_statement&pm=2923&rd=5854

#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

class TallPeople
{
public:
    vector<int> getPeople(vector<string> people)
    {
        vector<int> shortestInRow;
        vector<int> tallestinColumn;

        // row loop
        for (int i = 0; i < people.size(); i++)
        {
            vector<int> row;
            istringstream iss(people[i]);
            while (iss)
            {
                int sub;
                iss >> sub;
                row.push_back(sub);
            }

            int shortest = numeric_limits<int>::max();

            // column loop
            for (int j = 0; j < row.size(); j++)
            {
                if (row[j] < shortest)
                    shortest = row[j];

                // calculate tallest in each column
                if (i == 0)
                {
                    tallestinColumn.push_back(row[j]);
                }
                else if (row[j] > tallestinColumn[j])
                {
                    tallestinColumn[j] = row[j];
                }
            }

            // add shortest in this row to vector
            shortestInRow.push_back(shortest);
        }

        return{ *max_element(shortestInRow.begin(), shortestInRow.end()), *min_element(tallestinColumn.begin(), tallestinColumn.end()) };
    }
};
