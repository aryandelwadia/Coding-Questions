//Link
//https://www.naukri.com/code360/problems/remove-duplicates-from-unsorted-linked-list_1069331

#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    // Write your code here
    map<int, bool> elements;

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL) {
        if (elements.find(temp->data) != elements.end()) {
            prev->next = temp->next;
            delete temp;
        } else {
            elements[temp->data] = true;
            prev = temp;
        }
        temp = prev->next;
    }

    return head;
}