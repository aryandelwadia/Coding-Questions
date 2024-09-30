//link
//https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
#include <bits/stdc++.h>

class compare {
public:
  bool operator()(Node *a, Node *b) { return a->data > b->data; }
};

Node* mergeKLists(vector<Node*> &listArray) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < listArray.size(); i++) {
        if (listArray[i]) {
            pq.push(listArray[i]);
        }
    }

    Node *head = NULL;
    Node *tail = NULL;

    while (!pq.empty()) {
        Node *top = pq.top(); 
        pq.pop();
        
        if (top->next) {
            pq.push(top->next);
        }

        if (head == NULL) {
            head = top; 
            tail = top; 
        } else {
            tail->next = top; 
            tail = top;       
        }
    }

    tail->next = NULL; 
    return head; 
}