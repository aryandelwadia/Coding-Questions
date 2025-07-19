//link
//https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution {
public:
    int solve(vector<vector<int>>& matrix){
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> curr(n, 0);
        vector<int> next(n, 0);

        for(int i = 0; i < n; i++){
            next[i] = matrix[n - 1][i];
        }

        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int left = j > 0 ? next[j - 1] : INT_MAX;
                int middle = next[j];
                int right = j < n - 1 ? next[j + 1] : INT_MAX;

                curr[j] = matrix[i][j] + min(left, min(middle, right));
            }
            next = curr;
        }
        
        int ans = next[0];
        for(int i = 0; i < n; i++){
            ans = min(ans, next[i]);
        }
        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        return solve(matrix);        
    }
};