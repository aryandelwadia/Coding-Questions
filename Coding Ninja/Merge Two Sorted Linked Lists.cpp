//Link
//https://www.naukri.com/code360/problems/merge-two-sorted-linked-lists_800332

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int> *head = NULL;
    Node<int> *current = NULL;
    Node<int> *temp1 = first;
    Node<int> *temp2 = second;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1 -> data < temp2 -> data){
            if(head == NULL){
                Node<int> *newNode = new Node(temp1 -> data);
                head = newNode;
                current = head;
            }
            else{
                Node<int> *newNode = new Node(temp1 -> data);
                current -> next = newNode;
                current = current -> next;
            }
            temp1 = temp1 -> next;
        }
        else{
            if(head == NULL){
                Node<int> *newNode = new Node(temp2 -> data);
                head = newNode;
                current = head;
            }
            else{
                Node<int> *newNode = new Node(temp2 -> data);
                current -> next = newNode;
                current = current -> next;
            }
            temp2 = temp2 -> next;
        }
    }

    while(temp1 != NULL){
            if(head == NULL){
                Node<int> *newNode = new Node(temp1 -> data);
                head = newNode;
                current = head;
            }
            else{
                Node<int> *newNode = new Node(temp1 -> data);
                current -> next = newNode;
                current = current -> next;
            }
            temp1 = temp1 -> next;
    }

    while(temp2 != NULL){
            if(head == NULL){
                Node<int> *newNode = new Node(temp2 -> data);
                head = newNode;
                current = head;
            }
            else{
                Node<int> *newNode = new Node(temp2 -> data);
                current -> next = newNode;
                current = current -> next;
            }
            temp2 = temp2 -> next;
    }

    return head;
}
