//link
//https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* prev = NULL;
        Node* curr = head;
        bool flag = false;
        
        while(curr -> data < data){
            prev = curr;
            curr = curr -> next;
            if(curr == head){
                flag = true;
                break;
            }
        }
        
        if(flag){
            Node* newNode = new Node(data);
            prev -> next = newNode;
            newNode -> next = head;
        }
        else{
            if(prev != NULL){
                Node* newNode = new Node(data);
                prev -> next = newNode;
                newNode -> next = curr;
            }
            else{
                Node* temp = head;
                while(temp -> next != head){
                    temp = temp -> next;
                }
                Node* newNode = new Node(data);
                newNode -> next = head;
                temp -> next = newNode;
                head = newNode;
                
            }
        }
        
        return head;
        
    }
};