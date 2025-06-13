//link
//https://www.geeksforgeeks.org/problems/koko-eating-bananas/1

class Solution {
  public:
    int solve(vector<int>& arr, int mid){
        int ans = 0;
        for(int num : arr){
            ans += (num + mid - 1) / mid;
        }
        return ans;
    }
  
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        int h = 0;
        for(int i = 0; i < n; i++){
            h = max(h, arr[i]);
        }
        
        int ans = h;
        int l = 1;
        int mid = l + (h - l) / 2;
        while(l <= h){
            mid = l + (h - l) / 2;
            int t = solve(arr, mid);
            if(t > k){
                l = mid + 1;
            }
            else{
                h = mid - 1;
                ans = mid;
            }
        }
        
        return ans;
    }
};