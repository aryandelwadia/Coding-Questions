//link
//https://leetcode.com/problems/number-of-enclaves

class Solution {
private:
    void dfs(int r, int c, vector<vector<int>> &visited, vector<vector<int>>& grid){
        visited[r][c] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && !visited[nr][nc] && grid[nr][nc] == 1){
                dfs(nr, nc, visited, grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            if(!visited[0][i] && grid[0][i] == 1){
                dfs(0, i, visited, grid);
            }

            if(!visited[m - 1][i] && grid[m - 1][i] == 1){
                dfs(m - 1, i, visited, grid);
            }
        }

        for(int i = 0; i < m; i++){
            if(!visited[i][0] && grid[i][0] == 1){
                dfs(i, 0, visited, grid);
            }

            if(!visited[i][n - 1] && grid[i][n - 1] == 1){
                dfs(i, n - 1, visited, grid);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j]){
                    ans++;
                }
            }
        }

        return ans;
    }
};