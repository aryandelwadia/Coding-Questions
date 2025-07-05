//link
//https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int l = 0, r = 0;
        int ans = 0;
        unordered_map<int, int> m;
        
        while(r < n){
            m[arr[r]]++;
            if(m.size() > k){
                while(m.size() > k){
                    m[arr[l]]--;
                    if(m[arr[l]] == 0){
                        m.erase(arr[l]);
                    }
                    l++;
                }
            }
            
            ans += r - l + 1;
            r++;
        }
        
        return ans;
    }
};