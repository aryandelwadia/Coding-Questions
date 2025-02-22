//link
//https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool solveTab(vector<int> &arr, int total){
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(total + 1, 0));
        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }
        
        for(int index = n - 1; index >= 0; index--){
            for(int target = 0; target <= total / 2; target++){
                bool include = 0;
                if(target - arr[index] >= 0){
                    include = dp[index + 1][target-arr[index]];
                }
                bool exclude = dp[index + 1][target];
                dp[index][target] = include || exclude;
            }
        }
        
        return dp[0][total / 2];
        
    }
  
    bool equalPartition(vector<int>& arr) {
        // code here
        int total = 0;
        for(auto &i : arr){
            total += i;
        }
        
        if(total % 2 != 0){
            return false;
        }
        
        return solveTab(arr, total);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends