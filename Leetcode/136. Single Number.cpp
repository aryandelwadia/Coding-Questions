//link
//https://leetcode.com/problems/single-number/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res^=nums[i];
        }
        return res;
    }
};