//link
//https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
    public:
        bool solve(vector<int>& nums, int total){
            vector<vector<int>> dp(nums.size() + 1, vector<int>(total + 1, 0));
            for(int i = 0 ; i <= nums.size(); i++){
                dp[i][0] = true;
            }
    
            for(int index = nums.size() - 1; index >= 0; index--){
                for(int target = 0; target <= total / 2; target++){
                    bool inc = 0;
                    if(target - nums[index] >= 0){
                        inc = dp[index + 1][target - nums[index]];
                    }
                    bool exc = dp[index + 1][target];
                    dp[index][target] = inc || exc;
                }
            }
    
            return dp[0][total / 2];
        }
    
        bool canPartition(vector<int>& nums) {
            int total = 0;
            for(int i = 0; i < nums.size(); i++){
                total += nums[i];
            }
    
            if(total % 2 != 0){
                return false;
            }
    
            return solve(nums, total);
        }
    };