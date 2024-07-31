//Link
//https://www.naukri.com/code360/problems/add-two-numbers-as-linked-lists_1170520

#include<math.h>
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    // long long number1 = 0;
    // long long number2 = 0;

    // Node *temp = num1;
    // long long i = 0;

    // while(temp != NULL){
    //     number1 = number1 + ((temp -> data) * pow(10, i));
    //     i++; 
    //     temp = temp -> next;
    // }
    
    // temp = num2;
    // i = 0;

    // while(temp != NULL){
    //     number2 = number2 + ((temp -> data) * pow(10, i));
    //     i++; 
    //     temp = temp -> next;
    // }

    // long long n = number1 + number2;

    // Node *head = NULL;
    // Node *current = head;

    // while (n > 0){
    //     int r = n % 10;
    //     Node *newNode = new Node(r);
        
    //     if (head == NULL) {
    //         head = newNode;
    //         current = head;
    //     } else {
    //         current -> next = newNode;
    //         current = current -> next;
    //     }
        
    //     n = n / 10;
    // }

    // return head;

    Node *temp1 = num1;
    Node *temp2 = num2;

    int carry = 0;
    int n;

    Node *head = NULL;
    Node *current = head;

    while(temp1 != NULL && temp2 != NULL){
        n = temp1 -> data + temp2 -> data + carry;
        carry = n / 10;
        n = n % 10;
        Node *newNode = new Node(n);

        if(head == NULL){
            head = newNode;
            current = head;
        }
        else{
            current -> next = newNode;
            current = current -> next;
        }

        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }

    while(temp1 != NULL){
        n = temp1 -> data + carry;
        carry = n / 10;
        n = n % 10;
        Node *newNode = new Node(n);

        if(head == NULL){
            head = newNode;
            current = head;
        }
        else{
            current -> next = newNode;
            current = current -> next;
        }
        temp1 = temp1 -> next;
    }

    while(temp2 != NULL){
        n = temp2 -> data + carry;
        carry = n / 10;
        n = n % 10;
        Node *newNode = new Node(n);

        if(head == NULL){
            head = newNode;
            current = head;
        }
        else{
            current -> next = newNode;
            current = current -> next;
        }
        temp2 = temp2 -> next;
    }

    if(carry){
        Node *newNode = new Node(carry);

        if(head == NULL){
            head = newNode;
            current = head;
        }
        else{
            current -> next = newNode;
            current = current -> next;
        }
    }

    return head;
}
