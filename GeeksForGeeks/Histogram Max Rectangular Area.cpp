//link
//https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    void nextSmaller(vector<int> &next, int n, vector<int> &arr){
        stack<int> st;
        st.push(-1);
        
        for(int i = n - 1; i >= 0; i--){
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            
            next[i] = st.top();
            st.push(i);
        }
    }
    
    void prevSmaller(vector<int> &prev, int n, vector<int> &arr){
        stack<int> st;
        st.push(-1);
        
        for(int i = 0; i < n; i++){
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            
            prev[i] = st.top();
            st.push(i);
        }
    }
    
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        int area = INT_MIN;
        
        vector<int> next(n, -1);
        nextSmaller(next, n, arr);
        
        vector<int> prev(n, -1);
        prevSmaller(prev, n, arr);
        
        for(int i = 0; i < n; i++){
            int l = arr[i];
            if(next[i] == -1){
                next[i] = n;
            }
            
            int b = next[i] - prev[i] - 1;
            int a = l * b;
            
            area = max(area, a);
        }
        
        return area;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends