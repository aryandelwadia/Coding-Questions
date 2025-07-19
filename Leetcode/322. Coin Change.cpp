//link
//https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int solve(vector<int>& coins, int amount){
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, 1e9));

        for (int t = 0; t <= amount; ++t) {
            if (t % coins[0] == 0) {
                dp[0][t] = t / coins[0];
            }
        }

        for(int i = 1; i < n; i++){
            for(int target = 0; target <= amount; target++){
                int exc = dp[i - 1][target];
                int inc = 1e9;
                if(coins[i] <= target){
                    inc = 1 + dp[i][target - coins[i]];
                }

                dp[i][target] = min(exc, inc);
            }
        }

        return dp[n - 1][amount] >= 1e9 ? -1 : dp[n - 1][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        return solve(coins, amount);
    }
};