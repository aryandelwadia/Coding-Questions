//link
//https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
private:
    int solve(vector<int>& cost, int i, vector<int> &dp){
        if(i == 0){
            return cost[0];
        }
        if(i == 1){
            return cost[1];
        }

        if(dp[i] != -1){
            return dp[i];
        }

        dp[i] = cost[i] + min(solve(cost, i - 1, dp), solve(cost, i - 2, dp));
        return dp[i];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return ans;
    }
};