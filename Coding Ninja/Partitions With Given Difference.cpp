//link
//https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628

#include <bits/stdc++.h> 

int solve(vector<int> &arr, int k){
    int mod = 1e9 + 7;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    if(arr[0] == 0){
        dp[0][0] = 2;
    }
    else{
        dp[0][0] = 1;
    }

    if(arr[0] != 0 && arr[0] <= k){
        dp[0][arr[0]] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int target = 0; target <= k; target++){
            int exc = dp[i - 1][target];
            int inc = 0;
            if(arr[i] <= target){
                inc = dp[i - 1][target - arr[i]];
            }

            dp[i][target] = (exc + inc) % mod;
        }
    }

    return dp[n - 1][k];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int total = 0;
    for(int i = 0; i < n; i++){
        total += arr[i];
    }

    if(total - d < 0 || (total - d) % 2 != 0){
        return 0;
    }

    return solve(arr, (total - d) / 2);
}


