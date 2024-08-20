//link
//https://leetcode.com/problems/largest-local-values-in-a-matrix/

class Solution {
public:

    int largestnumber(vector<vector<int>>& grid, int m, int n){
        int maxNum = 0;
        for(int i = m; i < m + 3; i++){
            for(int j = n; j < n + 3; j++){
                maxNum = max(maxNum, grid[i][j]);
            }
        }
        return maxNum;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int> (n - 2));
        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < n - 2; j++){
                ans[i][j] = largestnumber(grid, i, j);
            }
        }

        return ans;
    }
};