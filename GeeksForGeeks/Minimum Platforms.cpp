//link
//http://geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution {
    public:
      // Function to find the minimum number of platforms required at the
      // railway station such that no train waits.
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          // Your code here
          sort(arr.begin(), arr.end());
          sort(dep.begin(), dep.end());
          
          int i = 0, j = 0, ans = 0, p = 0;
          
          while(i < arr.size() && j < dep.size()){
              if(arr[i] <= dep[j]){
                  i++;
                  p++;
              }
              else{
                  j++;
                  p--;
              }
              ans = max(ans, p);
          }
          
          return ans;
      }
  };