class Solution {
public:
    int m, n;
    
    int shortest_dist(vector<vector<char>>& maze, int i, int j) {
        queue<tuple<int, int, int>> q;
        q.push({i, j, 0});
        maze[i][j] = '+';
        int ti, tj, d, flag = 0;
        while (!q.empty()) {
            ti = get<0>(q.front());
            tj = get<1>(q.front());
            d = get<2>(q.front());
            if ((ti == 0 || tj == 0 || ti == m-1 || tj == n-1) && !(ti == i && tj == j)) {
                flag = 1;
                break;
            }
            q.pop();
            if ((0 <= ti-1) && (maze[ti-1][tj] == '.')) {
                maze[ti-1][tj] = '+';
                q.push({ti-1, tj, d+1});
            }
            if ((0 <= tj-1) && (maze[ti][tj-1] == '.')) {
                maze[ti][tj-1] = '+';
                q.push({ti, tj-1, d+1});
            }
            if ((ti+1 < m) && (maze[ti+1][tj] == '.')) {
                maze[ti+1][tj] = '+';
                q.push({ti+1, tj, d+1});
            }
            if ((tj+1 < n) && (maze[ti][tj+1] == '.')) {
                maze[ti][tj+1] = '+';
                q.push({ti, tj+1, d+1});
            }
        }
        if (flag)
            return d;
        return -1;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();
        return shortest_dist(maze, entrance[0], entrance[1]);
    }
};