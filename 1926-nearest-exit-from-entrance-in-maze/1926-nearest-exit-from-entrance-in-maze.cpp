class Solution {
    /*
        Variables used to store the number of rows and number of columns in the maze
        m: Number of Rows
        n: Number of Columns
    */
    int m, n;
public:    
    int shortest_dist(vector<int>& entry, vector<vector<char>>& maze) {
        /*
            We will use the Breadth-First-Search (BFS) to solve this problem, as this allows
            us to traverse all the paths of equal lengths at the same time. If we had used
            DFS we would have to maintain a variable to store the smallest/shortest distance.
            
            BFS has better Run Time Complexity compared to DFS as the former stops once the
            shortest path is found, but latter stops only when all the paths have been traversed.
            
            We can optimise the DFS by clipping the branch when the traversed path length
            exceedes the current shortest path length, but it being Recursive in nature has a 
            disadvantage in comparison to the Iterative approach of BFS.
        */
        queue<tuple<int, int, int>> q; // Queue to store the cells still to be visited
        int r, c, d; // Variables to store the current Row and Column alongwith the distance tarvelled
        q.push({entry[0], entry[1], 0}); // Adding the Entry Cell
        while (!q.empty()) {
            r = get<0>(q.front());
            c = get<1>(q.front());
            d = get<2>(q.front());
            q.pop();
            /*
                If the current cell lies on the boundary and is not the Entry Cell, then return
                the distance travelled till now, i.e., d
            */
            if (!(r == entry[0] && c == entry[1]) && (r == 0 || r == m-1 || c == 0 || c == n-1))
                return d;
            if ((r-1 >= 0) && (maze[r-1][c] == '.')) { // Check if we can move to the Up-Cell
                q.push({r-1, c, d+1});
                maze[r-1][c] = '+';
            }
            if ((r+1 < m) && (maze[r+1][c] == '.')) { // Check if we can move to the Down-Cell
                q.push({r+1, c, d+1});
                maze[r+1][c] = '+';
            }
            if ((c-1 >= 0) && (maze[r][c-1] == '.')) { // Check if we can move to the Left-Cell
                q.push({r, c-1, d+1});
                maze[r][c-1] = '+';
            }
            if ((c+1 < n) && (maze[r][c+1] == '.')) { // Check if we can move to the Right-Cell
                q.push({r, c+1, d+1});
                maze[r][c+1] = '+';
            }
        }
        return -1; // If no boundary cell found and all cells possible cells have been visited
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();
        return shortest_dist(entrance, maze);
    }
};