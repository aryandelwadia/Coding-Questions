//link
//https://leetcode.com/problems/guess-number-higher-or-lower-ii

class Solution {
    public:
        int solve(int n){
            vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    
            for(int start = n; start >= 1; start--){
                for(int end = start; end <= n; end++){
                    if(start == end){
                        continue;
                    }
                    else{
                        int ans = INT_MAX;
                        for(int i = start; i <= end; i++){
                            ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                        }
                        dp[start][end] = ans;
                    }
                }
            }
    
            return dp[1][n];
        }
    
        int getMoneyAmount(int n) {
            return solve(n);
        }
    };