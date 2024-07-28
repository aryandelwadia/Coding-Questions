//Link
//https://www.naukri.com/code360/problems/unique-sorted-list_2420283

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    // Write your code here

    if (head == NULL && head -> next == NULL){
        return head;
    }

    Node *temp = head;

    while(temp -> next != NULL){
        if(temp -> data == temp -> next -> data){
            if(temp -> next -> next) temp -> next -> next->prev=temp -> next -> prev;
            temp -> next = temp -> next -> next;

        }
        else{
            temp = temp -> next;
        }
    }

    return head;
}
