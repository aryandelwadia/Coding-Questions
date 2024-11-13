//link
//https://leetcode.com/problems/combination-sum-iii?envType=problem-list-v2&envId=backtracking

class Solution {
private:
    void solve(int k, int n, vector<vector<int>> &ans, vector<int> &result, int sum, int i){
        if(sum == n and k == 0){
            ans.push_back(result);
            return;
        }

        if(i > 9 || k <= 0){
            return;
        }

        if(sum + i <= n && k >= 0){
            result.push_back(i);
            sum += i;
            k--;
            solve(k, n, ans, result, sum, i + 1);
            k++;
            sum -= i;
            result.pop_back();
        }

        solve(k, n, ans, result, sum, i + 1);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> result;

        solve(k, n, ans, result, 0, 1);

        return ans;
    }
};