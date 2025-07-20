//link
//https://leetcode.com/problems/target-sum/description/

class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> curr(k + 1, 0);
        vector<int> next(k + 1, 0);

        if(nums[0] == 0) curr[0] = 2;
        else curr[0] = 1;

        if(nums[0] != 0 && nums[0] <= k) curr[nums[0]] = 1; 

        for(int i = 1; i < n; i++){
            for(int target = 0; target <= k; target++){
                int exc = curr[target];
                int inc = 0;
                if(nums[i] <= target){
                    inc = curr[target - nums[i]];
                }

                next[target] = inc + exc;
            }
            curr = next;
        }

        return curr[k];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum - target < 0 || (sum - target) % 2) return 0;
        
        return solve(nums, (sum - target) / 2);
    }
};