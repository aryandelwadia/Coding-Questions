//link
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
    private:
        int solve(int k, vector<int>& prices){
            vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
    
            for(int index = prices.size() - 1; index >= 0; index--){
                for(int buy = 0; buy <= 1; buy++){
                    for(int limit = 1; limit <= k; limit++){
                        int profit = 0;
                        if(buy){
                            int b = -prices[index] + dp[index + 1][0][limit];
                            int skip = dp[index + 1][1][limit];
                            profit = max(b, skip);
                        }
                        else{
                            int s = prices[index] + dp[index + 1][1][limit - 1];
                            int skip = dp[index + 1][0][limit];
                            profit = max(s, skip);
                        }
    
                        dp[index][buy][limit] = profit;
                    }
                }
            }
    
            return dp[0][1][k];
        }
    
    public:
        int maxProfit(int k, vector<int>& prices) {
            return solve(k, prices);
        }
    };