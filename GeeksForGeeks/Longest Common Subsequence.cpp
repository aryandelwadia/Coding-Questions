//link
//https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int solve(string &s1, string &s2, int i, int j){
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
        
        for(int i = s1.length() - 1; i >= 0; i--){
            for(int j = s2.length() - 1; j >= 0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else{
                    int n = dp[i + 1][j];
                    int m = dp[i][j + 1];
                    
                    dp[i][j] = max(n, m);
                }
            }
        }
        
        return dp[0][0];
    }
  
  public:
    int lcs(string &s1, string &s2) {
        // code here
        return solve(s1, s2, 0, 0);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends