//link
//https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<int> st;
    stack<int> minSt;
  
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        st.push(x);
        if(minSt.empty() || x <= minSt.top()){
            minSt.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(st.empty()){
            return;
        }
        
        if(st.top() == minSt.top()){
            minSt.pop();
        }
        st.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(st.empty()){
            return -1;
        }
        return st.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(minSt.empty()){
            return -1;
        }
        return minSt.top();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends