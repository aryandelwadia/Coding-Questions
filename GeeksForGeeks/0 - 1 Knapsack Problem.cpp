//link
//https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution {
    public:
      int solve(vector<int> &weight, vector<int> &value, int n, int capacity){
          vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
  
          for(int w = weight[0]; w <= capacity; w++){
              if(weight[0] <= capacity){
                  dp[0][w] = value[0];
              }
              else{
                  dp[0][w] = 0;
              }
          }
      
          for(int i = 1; i < n; i++){
              for(int w = 0; w <= capacity; w++){
                  int include = 0;
      
                  if(weight[i] <= w){
                      include = value[i] + dp[i - 1][w - weight[i]];
                  }
      
                  int exclude = dp[i - 1][w];
                  dp[i][w] = max(include, exclude);
              }
          }
      
          return dp[n - 1][capacity];
      }
    
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          // code here
          int n = val.size();
          return solve(wt, val, n, W);
      }
  };