//link
//https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  private:
    int solveMem(vector<int>& arr, int curr, int prev, vector<vector<int>> &dp){
        int n = arr.size();
        if(curr == n){
            return 0;
        }
        
        if(dp[curr][prev + 1] != -1){
            return dp[curr][prev + 1];
        }
        
        int include = 0;
        if(prev == -1 || arr[curr] > arr[prev]){
            include = 1 + solveMem(arr, curr + 1, curr, dp);
        }
        int exclude = solveMem(arr, curr + 1, prev, dp);
        
        return dp[curr][prev + 1] = max(include, exclude);
    }
    
    int solveTab(vector<int>& arr){
        int n = arr.size();
        
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);
        
        for(int curr = n - 1; curr >= 0; curr--){
            for(int prev = curr - 1; prev >= -1; prev--){
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev]){
                    include = 1 + nextRow[curr + 1];
                }
                int exclude = nextRow[prev + 1];
                
                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        
        return nextRow[0];
    }

  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solveMem(arr, 0, -1, dp);
        
        return solveTab(arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends