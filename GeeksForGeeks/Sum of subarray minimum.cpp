//link
//https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

class Solution {
  public:
    vector<int> findNSE(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        return ans;
    }
    
    vector<int> findPSE(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        return ans;
    }
  
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int total = 0;
        
        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            
            total += (left * right) * arr[i];
        }
        
        return total;
    }
};