//link
//https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int> ans(n, INT_MIN);
        stack<int> st;
        
        vector<int> prevSmaller(n, -1);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                prevSmaller[i] = st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        vector<int> nextSmaller(n, n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                nextSmaller[i] = st.top();
            }
            st.push(i);
        }
        
        for(int i = 0; i < n; i++){
            int len = nextSmaller[i] - prevSmaller[i] - 1;
            ans[len - 1] = max(arr[i], ans[len - 1]);
        }
        
        for(int i = n - 2; i >= 0; i--){
            ans[i] = max(ans[i], ans[i + 1]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends