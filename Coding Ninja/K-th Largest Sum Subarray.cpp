//link
//https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398

#include<bits/stdc++.h>

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue<int, vector<int>, greater<int>> minheap;

	int n = arr.size();
	for(int i = 0; i < n; i++){
		int sum = 0;

		for(int j = i; j < n; j++){
			sum += arr[j];

			if(minheap.size() < k){
				minheap.push(sum);
			}
			else{
				if(sum > minheap.top()){
					minheap.pop();
					minheap.push(sum);
				}
			}
		}
	}

	return minheap.top();
}