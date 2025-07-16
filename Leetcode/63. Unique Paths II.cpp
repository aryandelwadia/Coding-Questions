//link
//https://leetcode.com/problems/unique-paths-ii/description/

class Solution {
public:
    int solve(vector<vector<int>>& grid){
        if(grid[0][0] == 1){
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) {
                    curr[j] = 0;
                } else if(i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    int top = i > 0 ? prev[j] : 0;
                    int left = j > 0 ? curr[j - 1] : 0;
                    curr[j] = top + left;
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return solve(obstacleGrid);
    }
};