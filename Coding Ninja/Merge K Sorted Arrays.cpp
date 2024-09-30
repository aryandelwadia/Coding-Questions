//link
//https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379

#include <bits/stdc++.h> 

class node{
    public:
        int data; 
        int r;
        int c;

        node(int data, int r, int c){
            this -> data = data;
            this -> r = r;
            this -> c = c;
        }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a -> data > b -> data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*, vector<node*>, compare> pq;

    for(int i = 0; i < k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        pq.push(temp);
    }

    vector<int> ans;

    while(pq.size() > 0){
        node* top = pq.top();
        pq.pop();

        ans.push_back(top -> data);
        int r = top -> r;
        int c = top -> c;

        if(c + 1 < kArrays[r].size()){
            node* temp = new node(kArrays[r][c + 1], r, c + 1);
            pq.push(temp);
        }
    }

    return ans;
}
