//link
//https://www.naukri.com/code360/problems/kth-smallest-element_893056

#include <bits/stdc++.h>

int kthSmallest(int n,int k,vector<int> Arr)
{
    // Write your code here.
    priority_queue<int> pq;

    for(int i = 0; i < n; i++){
        if(pq.size() < k){
            pq.push(Arr[i]);
        }
        else{
            if(pq.top() > Arr[i]){
                pq.pop();
                pq.push(Arr[i]);
            }
        }
    }

    return pq.top();
}