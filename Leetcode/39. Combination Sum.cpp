//link
//https://leetcode.com/problems/combination-sum?envType=problem-list-v2&envId=backtracking

class Solution {
private:
    void solve(vector<int>& candidates, vector<vector<int>> &ans, int target,int i, int sum, vector<int> &result){
        if(sum == target){
            ans.push_back(result);
            return;
        }

        if(i >= candidates.size()){
            return;
        }

        if(sum + candidates[i] <= target){
            result.push_back(candidates[i]);
            sum += candidates[i];
            solve(candidates, ans, target, i, sum, result);
            sum -= candidates[i];
            result.pop_back();
        }
        
        solve(candidates, ans, target, i + 1, sum, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> result;
        solve(candidates, ans, target, 0, 0, result);

        return ans;
    }
};