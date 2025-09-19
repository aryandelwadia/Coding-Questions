//link
//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

class Solution {
public:
    int solve(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp){
        int m = matrix.size();
        int n = matrix[0].size();

        if(dp[r][c] != -1){
            return dp[r][c];
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};


        int maxLength = 1;

        for(int i = 0; i < 4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]) {
                maxLength = max(maxLength, 1 + solve(matrix, nr, nc, dp));
            }
        }

        dp[r][c] = maxLength;
        return dp[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int result = solve(matrix, i, j, dp);
                ans = max(ans, result);
            }
        }
        return ans;
    }
};