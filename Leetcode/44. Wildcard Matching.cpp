//link
//https://leetcode.com/problems/wildcard-matching/description/

class Solution {
public:
    bool solve(string& s, string& p){
        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;

        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
            else
                break;
        }


        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }

    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};