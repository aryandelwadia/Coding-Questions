//Link
//https://www.naukri.com/code360/problems/rotate-linked-list_920454

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     Node *temp = head;
     Node *prev = NULL;
     int count = 1;

     while(temp -> next != NULL){
          count ++;
          temp = temp -> next;
     }

     if (k > count){
          k = k % count;
     }
     else if (k == count){
          return head;
     }

     temp -> next = head;
     temp = head;
     count = count - k;

     for(int i = 0; i < count; i++){
          prev = temp;
          temp = temp -> next;
     }

     prev -> next = NULL;

     head = temp;

     return head;
}