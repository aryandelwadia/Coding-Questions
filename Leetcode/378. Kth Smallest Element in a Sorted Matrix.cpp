//link
//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/?envType=problem-list-v2&envId=heap-priority-queue

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

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<node*, vector<node*>, compare> pq;

        for(int i = 0; i < matrix.size(); i++){
            node* temp = new node(matrix[i][0], i, 0);
            pq.push(temp);
        }

        int i = 0;
        while(i < k - 1){
            node* top = pq.top();
            pq.pop();

            if(top -> c + 1< matrix.size()){
                pq.push(new node(matrix[top -> r][top -> c + 1], top -> r, top -> c + 1));
            }
            i++;
        }

        return pq.top() -> data;
    }
};