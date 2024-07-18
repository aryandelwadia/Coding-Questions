//Link
//https://leetcode.com/problems/subsets/

class Solution {
public:

    void solve(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>pair){
        if(i >= nums.size()){
            ans.push_back(pair);
            return ;
        }

        solve(nums, i + 1, ans, pair);

        int element = nums[i];
        pair.push_back(element);
        solve(nums, i + 1, ans, pair);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> pair;
        int i = 0;
        solve(nums, i, ans, pair);

        return ans;
    }
};