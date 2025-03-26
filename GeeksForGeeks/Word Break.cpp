//link
//https://www.geeksforgeeks.org/problems/word-break1352/1

class Solution {
    public:
      bool solve(string &s, vector<string> &dictionary, vector<int>& dp, int i){
          if(i == s.length()) return true;
          if(dp[i] != -1){
              return dp[i];
          }
          
          for (auto &w : dictionary){
              if (i + w.length() <= s.length() && s.substr(i, w.length()) == w){
                  if (solve(s, dictionary, dp, i + w.length())){
                      return dp[i] = true;
                  }
              }
          }
          
          return dp[i] = false;
      }
    
      bool wordBreak(string &s, vector<string> &dictionary) {
          // code here
          vector<int> dp(s.length() + 1, -1);
          return solve(s, dictionary, dp, 0);
      }
  };