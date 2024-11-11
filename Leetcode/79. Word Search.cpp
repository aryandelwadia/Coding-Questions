//link
//https://leetcode.com/problems/word-search?envType=problem-list-v2&envId=backtracking

class Solution {
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};

    bool solve(int x, int y, vector<vector<char>>& board, string word, int n){
        if(n == word.length()){
            return true;
        }

        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[n]){
            return false;
        }

        char temp = board[x][y];
        board[x][y] = '#';


        for(int i = 0; i < 4; i++){
            int nx = x + dr[i];
            int ny = y + dc[i];
            if(solve(nx, ny, board, word, n + 1)){
                return true;
            }
        }

        board[x][y] = temp;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(solve(i, j, board, word, 0)){
                    return true;
                }
            }
        }
        
        return false;
    }
};