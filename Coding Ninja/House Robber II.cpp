//link
//https://www.naukri.com/code360/problems/house-robber_839733

#include <bits/stdc++.h> 

long long solve(vector<int> &nums){
    long long n = nums.size();

    long long prev2 = 0;
    long long prev1 = nums[0];

    for(int i = 1; i < n; i++){
        long long inc = prev2 + nums[i];
        long long exc = prev1;

        long long ans = max(inc, exc);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if(n == 1){
        return valueInHouse[0];
    }

    vector<int> first, second;

    for(int i = 0; i < n; i++){
        if(i != n - 1){
            first.push_back(valueInHouse[i]);
        }
        if(i != 0){
            second.push_back(valueInHouse[i]);
        }
    }

    return max(solve(first), solve(second));
}