//Link
//https://www.naukri.com/code360/problems/interview-shuriken-42-detect-and-remove-loop_241049

/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *removeLoop(Node *head)
{
    // Write your code here.

    Node* slow = head;
    Node* fast = head;

    slow = slow -> next;
    fast = fast -> next -> next;

    while(slow != fast){
        if (fast == NULL){
            return head;
        }
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node* loopStart = head;

    while(loopStart != fast){
        loopStart = loopStart -> next;
        fast = fast -> next;
    }

    Node* temp = loopStart;

    while(temp -> next != loopStart){
        temp = temp -> next;
    }

    temp -> next = NULL; 

    return head; 
}