//link
//https://www.geeksforgeeks.org/problems/coin-piles5152/1

class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        int result = INT_MAX;
        int prev  = 0;
        
        for(int i = 0; i < n; i++){
            int index = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();
            
            if(i > 0){
                prev = prefix[i - 1];
            }
            
            int toRemove = prev + prefix[n - 1] - prefix[index - 1] - (arr[i] + k) * (n - index);
            result = min(result, toRemove);
        }
        
        return result;
    }
};
