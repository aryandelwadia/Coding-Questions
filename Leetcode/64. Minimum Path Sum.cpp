//link
//https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
public:
    int solve(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, INT_MAX);

        for(int i = 0; i < m; i++){
            vector<int> curr(n, INT_MAX);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) curr[j] = grid[i][j];
                else{
                    int left = j > 0 ? curr[j - 1] : INT_MAX;
                    int top = i > 0 ? prev[j] : INT_MAX;

                    curr[j] = grid[i][j] + min(left, top);
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        return solve(grid);
    }
};