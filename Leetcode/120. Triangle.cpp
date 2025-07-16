//link
//https://leetcode.com/problems/triangle/description/

class Solution {
public:
    int solve(vector<vector<int>>& triangle){
        int n = triangle.size();

        vector<int> front(n, 0);
        vector<int> curr(n, 0);
        
        for(int i = 0; i < n; i++){
            front[i] = triangle[n - 1][i];
        }

        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                int down = triangle[i][j] + front[j]; 
                int diag = triangle[i][j] + front[j + 1]; 

                curr[j] = min(down, diag);
            }
            front = curr;
        }

        return front[0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle);
    }
};