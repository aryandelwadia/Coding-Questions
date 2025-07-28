//link
//https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int solve(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i - 1; j >= -1; j--){
                int take = 0;
                if(j == -1 || nums[i] > nums[j]){
                    take = 1 + dp[i + 1][i + 1];
                }
                int notTake = dp[i + 1][j + 1];

                dp[i][j + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        return solve(nums);
    }
};