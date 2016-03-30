CaptureThemAll - SRM 207 Div 2 (3rd problem)
----------------------------------------
Full problem statement: [CaptureThemAll](https://community.topcoder.com/stat?c=problem_statement&pm=2915&rd=5853)

The solution treats the valid knight moves on the board as a graph thus making this a shortest path finding problem (in an unweighted, undirected graph) which can be done using Breadth First Search (BFS). We will first compute the shortest path from the knight to the rook and then to the queen. Then we will compute the shortest path from the knight to the queen and then to the rook. And finally return the minimum of these 2 paths.
