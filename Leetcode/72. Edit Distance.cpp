//link
//https://leetcode.com/problems/edit-distance

class Solution {
    private:
        int solve(string &a, string &b){
            vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
            for(int j = 0; j < b.length(); j++){
                dp[a.length()][j] = b.length() - j;
            }
            for(int i = 0; i < a.length(); i++){
                dp[i][b.length()] = a.length() - i;
            }
    
            for(int i = a.length() - 1; i >= 0; i--){
                for(int j = b.length() - 1; j >= 0; j--){
                    int ans = 0;
                    if(a[i] == b[j]){
                        dp[i][j] = dp[i + 1][j + 1];
                    }
                    else{
                        int insertStr = 1 + dp[i][j + 1];
                        int deleteStr = 1 + dp[i + 1][j];
                        int replaceStr = 1 + dp[i + 1][j + 1];
    
                        ans = min(insertStr, min(deleteStr, replaceStr));
                        dp[i][j] = ans;
                    }
                }
            }
    
            return dp[0][0];
        }    
    
    public:
        int minDistance(string word1, string word2) {
            return solve(word1, word2);
        }
    };