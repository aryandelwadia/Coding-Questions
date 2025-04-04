//link
//https://www.naukri.com/code360/problems/number-of-ways_3755252

#include <bits/stdc++.h> 
int solve(vector<int> &num, int tar){
    vector<int> dp(tar + 1);

    dp[0] = 1;
    for(int i = 1; i <= tar; i++){
        for(int j = 0; j < num.size(); j++){
            if(i - num[j] >= 0){
                dp[i] += dp[i - num[j]];
            }
        }
    }

    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    return solve(num, tar);
}