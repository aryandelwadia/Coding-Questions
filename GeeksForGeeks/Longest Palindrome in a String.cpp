//link
//https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string find(string& s, int i, int j){
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            i--;
            j++;
        }
        
        return s.substr(i + 1, j - i - 1);
    }
  
    string longestPalindrome(string &s) {
        // code here
        string maxStr = s.substr(0, 1);
        for(int i = 0; i < s.length() - 1; i++){
            string odd = find(s, i, i);
            string even = find(s, i, i + 1);
            
            if(odd.length() > maxStr.length()){
                maxStr = odd;
            }
            if(even.length() > maxStr.length()){
                maxStr = even;
            }
        }
        
        return maxStr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends