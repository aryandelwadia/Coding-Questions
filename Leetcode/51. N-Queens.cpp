//link
//https://leetcode.com/problems/n-queens?envType=problem-list-v2&envId=backtracking

class Solution {
private:

    void addSol(vector<vector<int>> &board, vector<vector<string>> &ans, int n){
        vector<string> temp;
        for(int i = 0; i < n; i++){
            string row = "";
            for(int j = 0; j < n; j++){
                row += (board[i][j] == 1) ? "Q" : ".";
            }
            temp.push_back(row);
        }

        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<int>> &board, int n){
        int x, y;

        x = row;
        y = col;

        while(y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            y--;
        }

        x = row;
        y = col;

        while(x >= 0 && y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            x--;
            y--;
        }

        x = row;
        y = col;

        while(x < n && y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<vector<int>> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            addSol(board, ans, n);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 1;
                solve(col + 1, board, ans, n);
                board[row][col] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<vector<string>> ans;

        solve(0, board, ans, n);

        return ans;
    }
};