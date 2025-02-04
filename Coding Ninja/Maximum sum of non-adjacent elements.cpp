//link
//https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
int solve(vector<int> &nums){
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for(int i = 1; i < n; i++){
        int inc = prev2 + nums[i];
        int exc = prev1;

        int ans = max(inc, exc);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solve(nums);
}