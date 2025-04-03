//link
//https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

class Solution {
    public:
      int orangesRotting(vector<vector<int>>& mat) {
          // Code here
          int n = mat.size();
          int m = mat[0].size();
          
          queue<pair<pair<int, int>, int>> q;
          vector<vector<int>> visited(n, vector<int>(m, 0));
          int tm = 0;
          int drow[] = {-1, 0, 1, 0};
          int dcol[] = {0, 1, 0, -1};
          
          for(int i = 0; i < n; i++){
              for(int j = 0; j < m; j++){
                  if(mat[i][j] == 2){
                      visited[i][j] = 2;
                      q.push({{i, j}, 0});
                  }
              }
          }
          
          while(!q.empty()){
              auto front = q.front();
              q.pop();
              int r = front.first.first;
              int c = front.first.second;
              int t = front.second;
              tm = max(t, tm);
              
              for(int i = 0; i < 4; i++){
                  int nr = r + drow[i];
                  int nc = c + dcol[i];
                  if(nr >= 0 && nr < n && nc >= 0 && nc < m && visited[nr][nc] != 2 && mat[nr][nc] == 1){
                      q.push({{nr, nc}, t + 1});
                      visited[nr][nc] = 2;
                  }
              }
          }
          
          for(int i = 0; i < n; i++){
              for(int j = 0; j < m; j++){
                  if(mat[i][j] == 1 && visited[i][j] != 2){
                      return -1;
                  }
              }
          }
          return tm;
      }
  };