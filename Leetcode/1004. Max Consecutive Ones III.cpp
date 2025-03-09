//link
//https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int ans = 0, l = 0, r = 0, zero = 0;
    
            while(r < nums.size()){
                if(nums[r] == 0) zero++;
                while(zero > k){
                    if(nums[l] == 0) zero--;
                    l++;
                }
                if(zero <= k){
                    int len = r - l + 1;
                    ans = max(ans, len);
                }
                r++;
            }
            return ans;
        }
    };