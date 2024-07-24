//Link
//https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644

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

Node*reverse(Node* head, int k, int n){
    if (head == NULL){
        return NULL;
    }

    
    Node *nextone = NULL;
    Node *current = head;
    Node *prev = NULL;
    int i = 0;

    if (n >= k){
        while (current != NULL && i < k){
            nextone = current -> next;
            current -> next = prev;
            prev = current;
            current = nextone;
            i++;
        }

        n = n - k;

        if (current != NULL){
            head -> next = reverse(nextone, k, n);
        }

        return prev;
    }
    else{
        return head;
    }

}

Node* kReverse(Node* head, int k) {
    // Write your code here.
    int n = 1;
    Node* temp = head;

    while (temp -> next != NULL){
        temp = temp -> next;
        n++;
    }

    return reverse(head, k, n);
}