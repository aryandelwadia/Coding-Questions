//link
//https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        
        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;  
        int steps = 1;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                if (r == n - 1 && c == n - 1) {
                    return steps;
                }
                
                for (int j = 0; j < 8; j++) {
                    int nr = r + drow[j];
                    int nc = c + dcol[j];
                    
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};