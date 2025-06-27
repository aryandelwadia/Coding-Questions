//link
//https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

class Solution {
  public:
    int solve(int i, int j, int n, vector<vector<vector<int>>>& dp){
        if(i < 0 || i >= 4 || j < 0 || j >= 3 || (i == 3 && (j == 0 || j == 2))){
            return 0;
        }
        
        if(n == 1){
            return 1;
        }
        
        if(dp[i][j][n] != -1){
            return dp[i][j][n];
        }
        
        int result = 0;
        result = solve(i, j, n - 1, dp) + solve(i - 1, j, n - 1, dp) + solve(i + 1, j, n - 1, dp) + solve(i, j - 1, n - 1, dp) + solve(i, j + 1, n - 1, dp);
        
        return dp[i][j][n] = result;
    }
  
    int getCount(int n) {
        // code here
        int ans = 0;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(20, -1)));
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                ans += solve(i, j, n, dp);
            }
        }
        
        return ans;
    }
};