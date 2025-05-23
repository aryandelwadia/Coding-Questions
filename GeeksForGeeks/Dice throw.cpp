//link
//https://www.geeksforgeeks.org/problems/dice-throw5349/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int solve(int m, int n, int x){
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= x; j++){
                int ans = 0;
                for(int k = 1; k <= m; k++){
                    if(j - k >= 0){
                        ans = ans + dp[i - 1][j - k];
                    }
                }
                dp[i][j] = ans;
            }
        }
        
        return dp[n][x];
    }
 
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        return solve(m, n, x);
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        int m, n, x;
        cin >> m >> n >> x;

        Solution ob;
        cout << ob.noOfWays(m, n, x) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends