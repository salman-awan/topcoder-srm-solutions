// CaptureThemAll – SRM 207 Div 2 (3rd problem)
// Full problem statement: https://community.topcoder.com/stat?c=problem_statement&pm=2915&rd=5853

#pragma once

#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct Position
{
    int row, col;

    Position(int _row, int _col) : row(_row), col(_col)
    {}

    bool operator==(const Position& other) const
    {
        return (this->row == other.row && this->col == other.col);
    }

    bool operator<(const Position& other) const
    {
        // less-than comparison with row priority
        if (this->row != other.row)
            return (this->row < other.row);
        else
            return (this->col < other.col);
    }
};

class CaptureThemAll
{
public:
    int fastKnight(string knight, string rook, string queen)
    {
        // the solution below treats the valid knight moves on the board as a graph
        // thus making this a shortest path finding problem (in an unweighted, undirected graph)
        // we will first compute the shortest path from the knight to the rook and then to the queen
        // then we will compute the shortest path from the knight to the queen and then to the rook
        // and finally return the minimum of these 2 paths

        // get initial positions of knight, rook and queen
        auto knight_pos = Position(knight[1] - '1', knight[0] - 'a');
        auto rook_pos = Position(rook[1] - '1', rook[0] - 'a');
        auto queen_pos = Position(queen[1] - '1', queen[0] - 'a');

        // get shortest path from knight -> rook -> queen
        int path1 = shortestPath(knight_pos, rook_pos) + shortestPath(rook_pos, queen_pos);

        // get shortest path from knight -> queen -> rook
        int path2 = shortestPath(knight_pos, queen_pos) + shortestPath(queen_pos, rook_pos);

        // return the minimum of path1 and path2
        return min(path1, path2);
    }

private:
    int shortestPath(const Position& start, const Position& end)
    {
        // this function implements BFS to find the shortest path from the start position to the end position

        // maintain a set of all visited positions
        set<Position> visited;

        // maintain a queue of all positions that we need to visit
        // the queue will store a std::pair to capture the shortest path lengths
        // for each position starting from the start position
        queue<pair<Position, int>> q;

        // add the start position to the queue to get started
        q.push(make_pair(start, 0));

        while (!q.empty())
        {
            // pop next position in the queue
            auto cur = q.front();
            q.pop();

            // add this position to the set of visited positions
            visited.insert(cur.first);

            // if we have reached the end position, return the shortest path length for this position
            if (cur.first == end)
                return cur.second;

            // otherwise get all valid knight moves from this position
            auto moves = moveKnight(cur.first);

            // push these knight moves into the queue if we have not visited those positions before
            // their shortest path length will be +1 the current shortest path length
            for (auto m : moves)
            {
                if (visited.find(m) == visited.end())
                    q.push(make_pair(m, cur.second + 1));
            }
        }

        // just a fail-safe to return an arbitrarily large value (in terms of chess board moves)
        // if we cannot find the end position ... this should never happen
        return 64;
    }

    vector<Position> moveKnight(const Position& pos)
    {
        // this functions generates all valid knight moves from the specified position
        // and returns a vector containing these positions

        vector<Position> result;

        // (-2, -1)
        if (pos.row > 1 && pos.col > 0)
            result.push_back(Position(pos.row - 2, pos.col - 1));

        // (-2, 1)
        if (pos.row > 1 && pos.col < 7)
            result.push_back(Position(pos.row - 2, pos.col + 1));

        // (-1, -2)
        if (pos.row > 0 && pos.col > 1)
            result.push_back(Position(pos.row - 1, pos.col - 2));

        // (1, -2)
        if (pos.row < 7 && pos.col > 1)
            result.push_back(Position(pos.row + 1, pos.col - 2));

        // (2, -1)
        if (pos.row < 6 && pos.col > 0)
            result.push_back(Position(pos.row + 2, pos.col - 1));

        // (2, 1)
        if (pos.row < 6 && pos.col < 7)
            result.push_back(Position(pos.row + 2, pos.col + 1));

        // (-1, 2)
        if (pos.row > 0 && pos.col < 6)
            result.push_back(Position(pos.row - 1, pos.col + 2));

        // (1, 2)
        if (pos.row < 7 && pos.col < 6)
            result.push_back(Position(pos.row + 1, pos.col + 2));

        return result;
    }
};
