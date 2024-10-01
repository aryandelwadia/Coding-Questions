//link
//https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356

#include<bits/stdc++.h>

class node {
    public:
        int data;
        int r;
        int c;

        node(int d, int row, int col){
            data = d;
            r = row;
            c = col;
        }
};

class compare{
    public:
        bool operator()(node*a, node*b){
            return a -> data > b -> data;
        }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
  // Write your code here.

    priority_queue<node*, vector<node*>, compare> pq;
    int mini = INT_MAX;    
    int maxi = INT_MIN;    

    for(int i = 0; i < k; i++){
        node* temp = new node(a[i][0], i, 0);
        mini = min(mini, a[i][0]);
        maxi = max(maxi, a[i][0]);
        pq.push(temp);
    }

    int start = mini;
    int end = maxi;

    while(!pq.empty()){
        node* top = pq.top();
        pq.pop();

        mini = top -> data;

        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        if(top -> c + 1 < n){
            maxi = max(maxi, a[top -> r][top -> c + 1]);
            pq.push(new node(a[top -> r][top -> c + 1], top -> r, top -> c + 1));
        }
        else{
            break;
        }
    }

    return end - start + 1;
}