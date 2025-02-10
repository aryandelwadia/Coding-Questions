//link
//https://www.naukri.com/code360/problems/0-1-knapsack_920542

#include <bits/stdc++.h> 
int solve(vector<int> &weight, vector<int> &value, int n, int capacity){
	vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

	for(int w = weight[0]; w <= capacity; w++){
		if(weight[0] <= capacity){
			dp[0][w] = value[0];
		}
		else{
			dp[0][w] = 0;
		}
	}

	for(int i = 1; i < n; i++){
		for(int w = 0; w <= capacity; w++){
			int include = 0;

			if(weight[i] <= w){
				include = value[i] + dp[i - 1][w - weight[i]];
			}

			int exclude = dp[i - 1][w];
			dp[i][w] = max(include, exclude);
		}
	}

	return dp[n - 1][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return solve(weight, value, n, maxWeight);
}