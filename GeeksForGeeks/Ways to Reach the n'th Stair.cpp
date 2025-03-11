//link
//https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

class Solution {
    public:
      int solve(int n){
          int prev2 = 1;
          int prev1 = 1;
          int curr = 0;
          
          for(int i = 2; i <= n; i++){
              curr = prev2 + prev1;
              prev2 = prev1;
              prev1 = curr;
          }
          
          return prev1;
      }
      
      int countWays(int n) {
          // your code here
          return solve(n);
      }
  };
  