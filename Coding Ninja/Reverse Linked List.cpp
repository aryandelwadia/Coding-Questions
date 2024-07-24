//Link
//https://www.naukri.com/code360/problems/reverse-the-singly-linked-list_799897

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* current = head;
    LinkedListNode<int>* temp;


    while(current != NULL){
        temp = current -> next;
        current -> next = prev;
        prev = current;
        current = temp;

    }

    return prev;

}