//link
//https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1


class Solution {
    public:
      int solve(vector<int> &arr){
          vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
          
          for(int i = arr.size() - 1; i >= 0; i--){
              for(int j = i + 1; j < arr.size(); j++){
                  if(i + 1 == j) continue;
                  
                  int ans = INT_MAX;
                  
                  for(int k = i + 1; k < j; k++){
                      int res = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                      
                      ans = min(res, ans);
                  }
                  
                  dp[i][j] = ans;
              }
          }
          return dp[0][arr.size() - 1];
      }
    
      int matrixMultiplication(vector<int> &arr) {
          // code here
          return solve(arr);
      }
  };