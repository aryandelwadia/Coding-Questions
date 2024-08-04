//Link
//https://www.naukri.com/code360/problems/mergesort-linked-list_630514

/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/

node* findMidNode(node* head){
    node *slow = head;
    node *fast = head -> next;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

node *merge(node *left, node *right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    node *sorted = new node(-1);
    node *temp = sorted;

    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            left = left -> next;
            temp = temp -> next;
        }
        else{
            temp -> next = right;
            right = right -> next;
            temp = temp -> next;
        }
    }

    while(left != NULL){
            temp -> next = left;
            left = left -> next;
            temp = temp -> next;
    }

    while(right != NULL){
            temp -> next = right;
            right = right -> next;
            temp = temp -> next;
    }

    return sorted -> next;
}

node* mergeSort(node *head) {
    // Write your code here.

    if(head == NULL || head -> next == NULL){
        return head;
    }

    node *mid = findMidNode(head);
    node *left = head;
    node *right = mid -> next;
    mid -> next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node *sorted = merge(left, right);

    return sorted;
}
