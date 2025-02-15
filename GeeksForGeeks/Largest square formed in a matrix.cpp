//link
//https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    int solve(vector<vector<int>> &mat, int &maxi){
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];
                
                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
                
            }
        }
        
        return dp[0][0];
        
    }
    
  public:
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        
        int maxi = 0;
        solve(mat, maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(mat) << "\n"
             << "~\n";
    }
    return 0;
}
// } Driver Code Ends