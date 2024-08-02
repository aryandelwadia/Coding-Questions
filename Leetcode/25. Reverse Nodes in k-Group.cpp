//link
//https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverse(ListNode* head, int k, int n) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* nextone = NULL;
        ListNode* current = head;
        ListNode* prev = NULL;
        int i = 0;

        if (n >= k) {
            while (current != NULL && i < k) {
                nextone = current->next;
                current->next = prev;
                prev = current;
                current = nextone;
                i++;
            }

            n = n - k;

            if (current != NULL) {
                head->next = reverse(nextone, k, n);
            }

            return prev;
        } else {
            return head;
        }
    }

    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 1;
        ListNode* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
            n++;
        }

        return reverse(head, k, n);
    }
};