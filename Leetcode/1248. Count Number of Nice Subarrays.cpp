//link
//https://leetcode.com/problems/count-number-of-nice-subarrays

class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k < 0){
            return 0;
        }
        
        int l = 0, r = 0, count = 0, ans = 0;
        while(r < nums.size()){
            if(nums[r] % 2 != 0){
                count++;
            }
            while(count > k){
                if(nums[l] % 2 != 0){
                    count--;
                }
                l++;
            }
            ans += r - l + 1;
            r++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};