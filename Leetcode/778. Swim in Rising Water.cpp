//link
//https://leetcode.com/problems/swim-in-rising-water

class Solution {
private:
    bool bfs(vector<vector<int>>& grid, int t){
        if(t < grid[0][0]){
            return false;
        }
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int r = front.first;
            int c = front.second;

            if (r == n - 1 && c == n - 1) return true;
            
            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && visited[nr][nc] == 0 && grid[nr][nc] <= t) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for(int i = 0; i < n * n; i++){
            bool res = bfs(grid, i);
            if(res){
                return i;
            }
        }

        return -1;
    }
};