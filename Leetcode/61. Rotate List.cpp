//link
//https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL || head -> next == NULL){
            return head;
        }

        ListNode *temp = head;
        ListNode *prev = NULL;
        int count = 0;

        while (temp != NULL){
            count++;
            prev = temp;
            temp = temp -> next;
        }

        if(k % count == 0){
            return head;
        }

        prev -> next = head;
        k = k % count;
        temp = head;
        prev = NULL;

        for(int i = 0; i < count - k; i++){
            prev = temp;
            temp = temp -> next;
        }

        prev -> next = NULL;
        head = temp;

        return head;
    }
};