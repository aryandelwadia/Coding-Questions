//Link
//https://leetcode.com/problems/permutations/

class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>>& ans, int i){
        if (i >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            solve(nums, ans, i + 1);
            swap(nums[j], nums[i]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;

        solve(nums, ans, i);
        return ans;
    }
};