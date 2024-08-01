//Link
//https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* current = NULL;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val < temp2->val) {
                if (head == NULL) {
                    ListNode* newNode = new ListNode(temp1->val);
                    head = newNode;
                    current = head;
                } else {
                    ListNode* newNode = new ListNode(temp1->val);
                    current->next = newNode;
                    current = current->next;
                }
                temp1 = temp1->next;
            } else {
                if (head == NULL) {
                    ListNode* newNode = new ListNode(temp2->val);
                    head = newNode;
                    current = head;
                } else {
                    ListNode* newNode = new ListNode(temp2->val);
                    current->next = newNode;
                    current = current->next;
                }
                temp2 = temp2->next;
            }
        }

        while (temp1 != NULL) {
            if (head == NULL) {
                ListNode* newNode = new ListNode(temp1->val);
                head = newNode;
                current = head;
            } else {
                ListNode* newNode = new ListNode(temp1->val);
                current->next = newNode;
                current = current->next;
            }
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            if (head == NULL) {
                ListNode* newNode = new ListNode(temp2->val);
                head = newNode;
                current = head;
            } else {
                ListNode* newNode = new ListNode(temp2->val);
                current->next = newNode;
                current = current->next;
            }
            temp2 = temp2->next;
        }

        return head;
    }
};