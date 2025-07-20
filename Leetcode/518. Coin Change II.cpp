//link
//https://leetcode.com/problems/coin-change-ii/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<unsigned long long> dp(amount + 1, 0); 
        dp[0] = 1;
        for (int &coin : coins) {
            for (int target = coin; target <= amount; ++target) {
                dp[target] += dp[target - coin];
            }
        }
        return dp[amount];        
    }
};