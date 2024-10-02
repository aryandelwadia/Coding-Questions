//link
//https://www.naukri.com/code360/problems/median-in-a-stream_975268

#include<bits/stdc++.h>

int signum(int a, int b){
	if(a == b){
		return 0;
	}
	else if(a > b){
		return 1;
	}
	else{
		return -1;
	}
}

void callMedian(int &element, priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int> > &minheap, int &median){

	switch(signum(maxheap.size(), minheap.size())){
		case 0:
		if(element > median){
			minheap.push(element);
			median = minheap.top();
		}
		else{
			maxheap.push(element);
			median = maxheap.top();
		}
		break;

		case 1:
		if(element > median){
			minheap.push(element);
			median = (maxheap.top() + minheap.top()) / 2;
		}
		else{
			minheap.push(maxheap.top());
			maxheap.pop();
			maxheap.push(element);
			median = (maxheap.top() + minheap.top()) / 2;
		}
		break;

		case -1:
		if(element > median){
			maxheap.push(minheap.top());
			minheap.pop();
			minheap.push(element);
			median = (maxheap.top() + minheap.top()) / 2;
		}
		else{
			maxheap.push(element);
			median = (maxheap.top() + minheap.top()) / 2;
		}
		break;
	}	
}

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 

	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int> > minheap;
	int median = 0;
	vector<int> ans;

	for(int i = 0; i < n; i++){
		callMedian(arr[i], maxheap, minheap, median);
		ans.push_back(median);
	}

	return ans;
}
