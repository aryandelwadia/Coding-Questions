//link
//https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        unordered_map<int, int> m;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            m[arr[i]]++;
        }
        
        vector<int> ans(n, -1);
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && m[arr[i]] > m[arr[st.top()]]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            
            st.push(i);
        }
        
        return ans;
    }
};
