//Link
//https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937

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

Node* addNode(Node* &nodes, int n){
    Node *newNode = new Node(n);
    nodes -> next = newNode;
    nodes = newNode;

    return nodes;
}

Node* sortList(Node *head){
    // Write your code here.
    Node *temp = head;
    Node *zeroNode = new Node(-1);
    Node *zeroHead = zeroNode;
    Node *oneNode = new Node(-1);
    Node *oneHead = oneNode;
    Node *twoNode = new Node(-1);
    Node *twoHead = twoNode;
    
    while(temp != NULL){
        if(temp -> data == 0){
            addNode(zeroNode, 0);
        }
        else if(temp -> data == 1){
            addNode(oneNode, 1);
        }
        else{
            addNode(twoNode, 2);
        }

        temp = temp -> next;
    }

    zeroNode -> next = oneHead -> next;
    oneNode -> next = twoHead -> next;

    head = zeroHead -> next;

    return head;
}