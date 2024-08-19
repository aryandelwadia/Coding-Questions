//link
//https://leetcode.com/problems/next-greater-element-ii/description/

#include<vector>
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 1){
            ans.push_back(-1);
            return ans;
        }

        int j;
        for(int i = 0; i < nums.size(); i++){
            if(i == nums.size() - 1){
                j = 0;
            }
            else{
                j = i + 1;
            }
            int nextGreater = nums[i];
            while(j != i){
                if(nums[j] > nextGreater){
                    ans.push_back(nums[j]);
                    break;
                }
                if(j == nums.size() - 1){
                    j = 0;
                }
                else{
                    j++;
                }
            }
            if(i == j){
                ans.push_back(-1);
            }
        }

        return ans;
    }
};