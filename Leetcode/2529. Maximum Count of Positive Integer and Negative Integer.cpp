//link
//https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer?envType=daily-question&envId=2025-03-12


class Solution {
    public:
        int maximumCount(vector<int>& nums) {
    
            int l = 0, r = nums.size() - 1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(nums[mid] >= 0){
                    r = mid - 1;
                }
                if(nums[mid] < 0){
                    l = mid + 1;
                }
            }
    
            int n = nums.size();
            int neg = l;
            int pos = n - l ;
    
            for(int i = l; i < n; i++){
                if(nums[i] == 0){
                    pos--;
                }
            }
    
            return max(neg, pos);
        }
    };