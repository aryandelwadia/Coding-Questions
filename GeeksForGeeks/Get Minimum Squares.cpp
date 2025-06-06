//link
//https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int n){
        vector<int> dp(n + 1, INT_MAX);
        
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j * j <= n; j++){
                int temp = j * j;
                if(i - temp >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - temp]);
                
            }
        }
        
        return dp[n];
    }
  
    int MinSquares(int n) {
        // Code here
        return solve(n);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends