//Link
//https://www.naukri.com/code360/problems/sum-of-two-arrays_893186

#include <bits/stdc++.h> 

int solve(vector<int>a, int n){
	int i = 0;
	int sum = 0;

	for(int j = n - 1; j >= 0; j--){
		sum += (a[j] * pow(10, i));
		i++;
	}

	return sum;
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.

	vector<int> ans;

	int n1 = solve(a, n);
	int n2 = solve(b, m);

	int n3 = n1 + n2;

	while(n3 > 0){
		int n = n3 % 10;
		ans.push_back(n);
		n3 = n3 / 10;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}