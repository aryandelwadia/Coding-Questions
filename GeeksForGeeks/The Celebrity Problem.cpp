//link
//https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    bool knows(vector<vector<int>> &mat, int a, int b, int n) {
        return mat[a][b] == 1;
    }
    
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> s;
        
        for(int i = 0; i < n; i++) {
            s.push(i);
        }
        
        while(s.size() > 1) {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(mat, a, b, n)) {
                s.push(b);
            } else {
                s.push(a);
            }
        }
        
        int ans = s.top();
        int zeroCount = 0;
        int oneCount = 0;
        
        for(int i = 0; i < n; i++) {
            if(mat[ans][i] == 0) {
                zeroCount++;
            }
        }
        
        if(zeroCount != n) {
            return -1;
        }
        
        for(int i = 0; i < n; i++) {
            if(mat[i][ans] == 1) {
                oneCount++;
            }
        }
        
        if(oneCount != n - 1) {
            return -1;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends