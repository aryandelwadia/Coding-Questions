//link
//https://leetcode.com/problems/distinct-subsequences/description/

class Solution {
public:
    int solve(string& s, string& t){
        int m = s.length();
        int n = t.length();

        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(int i = 0; i <= m; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++){
            dp[0][i] = 0;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % static_cast<int>(1e9 + 7);
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }

    int numDistinct(string s, string t) {
        return solve(s, t);
    }
};