//link
//https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> st;
        int n = q.size();
        
        for(int i = 0; i < k; i++){
            int element = q.front();
            q.pop();
            st.push(element);
        }
        
        while(!st.empty()){
            int element = st.top();
            st.pop();
            q.push(element);
        }
        
        for(int i = 0; i < n - k; i++){
            int element = q.front();
            q.pop();
            q.push(element);
        }
        
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends