//link
//https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int solve(string& s, string& revS){
        vector<vector<int>> dp(s.length() + 1, vector<int> (revS.length() + 1, 0));
        
        for(int i = s.length() - 1; i >= 0; i--){
            for(int j = revS.length() - 1; j >= 0; j--){
                if(s[i] == revS[j]){
                    dp[i][j] =  1 + dp[i + 1][j + 1];
                }
                else{
                    int n1 = dp[i + 1][j];
                    int n2 = dp[i][j + 1];
                    
                    dp[i][j] = max(n1, n2);
                }
            }
        }
        return dp[0][0];
    }
  
    int longestPalinSubseq(string &s) {
        // code here
        string revS = s;
        reverse(revS.begin(), revS.end());
        return solve(s, revS);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends