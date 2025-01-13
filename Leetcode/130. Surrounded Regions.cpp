//link
//https://leetcode.com/problems/surrounded-regions

class Solution {
private:
    void dfs(int r, int c, vector<vector<int>> &visited, vector<vector<char>> &board){
        visited[r][c] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && !visited[nr][nc] && board[nr][nc] == 'O'){
                dfs(nr, nc, visited, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++){
            if(!visited[0][i] && board[0][i] == 'O'){
                dfs(0, i, visited, board);
            }

            if(!visited[n - 1][i] && board[n - 1][i] == 'O'){
                dfs(n - 1, i, visited, board);
            }
        }

        for(int i = 0; i < n; i++){
            if(!visited[i][0] && board[i][0] == 'O'){
                dfs(i, 0, visited, board);
            }

            if(!visited[i][m - 1] && board[i][m - 1] == 'O'){
                dfs(i, m - 1, visited, board);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};