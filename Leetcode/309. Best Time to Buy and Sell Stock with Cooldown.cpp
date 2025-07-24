//link
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution {
public:
    int solve(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                int profit = INT_MIN;
                if(buy){
                    int b = -prices[i] + dp[i + 1][0];
                    int skip = dp[i + 1][1];
                    profit = max(b, skip);
                }
                else{
                    int s = i <= n - 2 ? prices[i] + dp[i + 2][1] : prices[i];
                    int skip = dp[i + 1][0];
                    profit = max(s, skip);
                }

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};