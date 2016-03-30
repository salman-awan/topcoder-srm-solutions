TallPeople - SRM 208 Div 1 (1st problem)
----------------------------------------

Full problem statement: [TallPeople](https://community.topcoder.com/stat?c=problem_statement&pm=2923&rd=5854)

The solution treats the valid knight moves on the board as a graph thus making this a shortest path finding problem (in an unweighted, undirected graph) which can be done using Breadth First Search (BFS). We will first compute the shortest path from the knight to the rook and then to the queen. Then we will compute the shortest path from the knight to the queen and then to the rook. And finally return the minimum of these 2 paths.