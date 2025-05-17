//link
//https://leetcode.com/problems/subarrays-with-k-different-integers/

class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k == 0){
            return 0;
        }
        unordered_map<int, int> m;
        int l = 0, r = 0;
        int n = nums.size();
        int count = 0;
        while(r < n){
            m[nums[r]]++;
            while(m.size() > k){
                m[nums[l]]--;
                if(m[nums[l]] == 0){
                    m.erase(nums[l]);
                }
                l++;
            }
            if(m.size() <= k){
                count += r - l + 1;
            }
            r++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};