//link
//https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

class Solution {
    public:
      void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j){
          int n = grid.size();
          int m = grid[0].size();
          
          visited[i][j] = 1;
          queue<pair<int, int>> q;
          q.push({i, j});
          int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
          int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
          
          while(!q.empty()){
              auto front = q.front();
              q.pop();
              
              int r = front.first;
              int c = front.second;
              
              for(int k = 0; k < 8; k++){
                  int nr = r + drow[k];
                  int nc = c + dcol[k];
                  if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 'L' && visited[nr][nc] == 0){
                      q.push({nr, nc});
                      visited[nr][nc] = 1;
                  }
              }
          }
      }
    
      int countIslands(vector<vector<char>>& grid) {
          // Code here
          int n = grid.size();
          int m = grid[0].size();
          
          vector<vector<int>> visited(n, vector<int>(m, 0));
          int ans = 0;
          
          for(int i = 0; i < n; i++){
              for(int j = 0; j < m; j++){
                  if(grid[i][j] == 'L' && visited[i][j] == 0){
                      bfs(grid, visited, i, j);
                      ans++;
                  }
              }
          }
          
          return ans;
      }
  };