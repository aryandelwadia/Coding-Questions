//link
//https://leetcode.com/problems/minimum-sideway-jumps

class Solution {
    private:
        int solve(vector<int> &obstacles){
            int n = obstacles.size() - 1;
            vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));
            dp[0][n] = 0;
            dp[1][n] = 0;
            dp[2][n] = 0;
            dp[3][n] = 0;
    
            for(int currpos = n - 1; currpos >= 0; currpos--){
                for(int currlane = 1; currlane < 4; currlane++){
                    if(obstacles[currpos + 1] != currlane){
                        dp[currlane][currpos] = dp[currlane][currpos + 1];
                    }
                    else{
                        int ans = 1e9;
                        for(int i = 1; i < 4; i++){
                            if(i != currlane && obstacles[currpos] != i){
                                ans = min(ans, 1 + dp[i][currpos + 1]);
                            }
                        }
                        dp[currlane][currpos] = ans;
                    }
                }
            }
    
            return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
        }
    
    public:
        int minSideJumps(vector<int>& obstacles) {
            return solve(obstacles);
        }
    };