//link
//https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ans = arr[0] + arr[1];
        
        for(int i = 1; i < n - 1; i++){
            ans = max(ans, arr[i] + arr[i + 1]);
        }
        
        return ans;
    }
};