//link
//https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    bool solve(vector<int>& nums){
        int n = nums.size();
        int maxReach = 0;
        
        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false; 
            maxReach = max(maxReach, i + nums[i]);
        }
        
        return true;
    }

    bool canJump(vector<int>& nums) {
        return solve(nums);
    }
};