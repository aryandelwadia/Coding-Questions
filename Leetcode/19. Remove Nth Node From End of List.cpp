//Link
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (n == 0){
            return head;
        }
        
        ListNode *temp = head;

        int count = 0;

        while(temp != NULL){
            count++;
            temp = temp -> next;
        }

        if(n == count){
            ListNode* newHead = head -> next;
            delete head;
            return newHead;
        }

        int toRemove = count - n;
        temp = head;

        for(int i = 0; i < toRemove - 1; i++){
            temp = temp -> next;
        }
        
        temp -> next = temp -> next -> next;

        return head;
    }
};