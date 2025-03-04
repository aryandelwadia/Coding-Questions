//link
//https://leetcode.com/problems/longest-common-subsequence

class Solution {
    private:
        int solve(string &text1, string &text2){
            vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
    
            for(int index1 = text1.length() - 1; index1 >= 0; index1--){
                for(int index2 = text2.length() - 1; index2 >= 0; index2--){
                    if(text1[index1] == text2[index2]){
                        dp[index1][index2] = 1 + dp[index1 + 1][index2 + 1];
                    }
                    else{
                        int n1 = dp[index1 + 1][index2];
                        int n2 = dp[index1][index2 + 1];
                        dp[index1][index2] = max(n1, n2);
                    }
                }
            }
            return dp[0][0];
        }
    
    public:
        int longestCommonSubsequence(string text1, string text2) {
            return solve(text1, text2);
        }
    };