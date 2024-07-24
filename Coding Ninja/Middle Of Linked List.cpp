//Link
//https://www.naukri.com/code360/problems/middle-of-linked-list_973250

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

Node *findMiddle(Node *head) {
  // Write your code here
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node *temp = head;

    int i = 1;
    while(temp -> next != NULL){
        temp = temp -> next;
        i++;
    }

    i = i / 2;
    temp = head;

    for(int j = 0; j < i; j++){
        temp = temp -> next;
    }

    return temp;
}

