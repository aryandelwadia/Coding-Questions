//link
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
    public:
        int solve(vector<int>& prices){
            vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
    
            for(int index = prices.size() - 1; index >= 0; index--){
                for(int buy = 0; buy < 2; buy++){
                    int profit = 0;
                    if(buy){
                        int b = -prices[index] + dp[index + 1][0];
                        int skip = dp[index + 1][1];
                        profit = max(b, skip);
                    }
                    else{
                        int s = prices[index] + dp[index + 1][1];
                        int skip = dp[index + 1][0];
                        profit = max(s, skip);
                    }
    
                    dp[index][buy] = profit;
                }
            }
    
            return dp[0][1];
        }
    
        int maxProfit(vector<int>& prices) {
            // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
            return solve(prices);
        }
    };