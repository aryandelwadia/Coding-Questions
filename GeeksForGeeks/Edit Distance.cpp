//link
//https://www.geeksforgeeks.org/problems/edit-distance3702/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(string& s1, string& s2, int i, int j){
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
        
        for(int j = 0; j < s2.length(); j++){
            dp[s1.length()][j] = s2.length() - j;
        }
        for(int i = 0; i < s1.length(); i++){
            dp[i][s2.length()] = s1.length() - i;
        }
        
        for(int i = s1.length() - 1; i >= 0; i--){
            for(int j = s2.length() - 1; j >= 0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else{
                    int insertKey = 1 + dp[i][j + 1];
                    int removeKey = 1 + dp[i + 1][j];
                    int replace = 1 + dp[i + 1][j + 1];
                    
                    dp[i][j] = min(insertKey, min(removeKey, replace));
                }
            }
        }
        
        return dp[0][0];
        
    }
  
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        return solve(s1, s2, 0, 0);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends