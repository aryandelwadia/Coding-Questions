//Link
//https://www.naukri.com/code360/problems/ayush-and-ninja-test_1097574

#include <bits/stdc++.h> 

bool isPossible(int n, int m, vector<int> time, int mid){
	int days = 1;
	int t = 0;
	for (int i = 0; i < m; i++){
		if(t + time[i] <= mid){
			t += time[i];
		}
		else{
			days++;
			if(days > n || time[i] > mid){
				return false;
			}
			t = time[i];
		}
	}
	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.

	int s = 0;
	int e = 0;
	long long ans = 0;

	for (int i = 0; i < m; i++){
		e += time[i];
	}

	int mid = s + (e - s) / 2;

	while(s <= e){
		if(isPossible(n, m, time, mid)){
			ans = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}

		mid = s + (e - s) / 2;
	}

	return ans;
}