//link
//https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int fresh = 0;
        queue<pair <pair<int, int>, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else{
                    visited[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int time = 0;
        int count = 0;

        while(!q.empty()){
            pair <pair<int, int>, int> p = q.front();
            q.pop();
            int r = p.first.first;
            int c = p.first.second;
            int t = p.second;
            time = max(time, t);

            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < m && nc >=0 && nc < n && visited[nr][nc] != 2 && grid[nr][nc] == 1){
                    q.push({{nr, nc}, t + 1});
                    visited[nr][nc] = 2;
                    count++;
                }
            }
        }

        if(count != fresh){
            return -1;
        }

        return time;
    }
};