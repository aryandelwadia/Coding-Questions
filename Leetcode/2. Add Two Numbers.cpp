//Link
//https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;
        int n;

        ListNode* head = NULL;
        ListNode* current = head;

        while (temp1 != NULL && temp2 != NULL) {
            n = temp1 -> val + temp2->val + carry;
            carry = n / 10;
            n = n % 10;
            ListNode* newNode = new ListNode(n);

            if (head == NULL) {
                head = newNode;
                current = head;
            } else {
                current->next = newNode;
                current = current->next;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (temp1 != NULL) {
            n = temp1->val + carry;
            carry = n / 10;
            n = n % 10;
            ListNode* newNode = new ListNode(n);

            if (head == NULL) {
                head = newNode;
                current = head;
            } else {
                current->next = newNode;
                current = current->next;
            }
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            n = temp2->val + carry;
            carry = n / 10;
            n = n % 10;
            ListNode* newNode = new ListNode(n);

            if (head == NULL) {
                head = newNode;
                current = head;
            } else {
                current->next = newNode;
                current = current->next;
            }
            temp2 = temp2->next;
        }

        if (carry) {
            ListNode* newNode = new ListNode(carry);

            if (head == NULL) {
                head = newNode;
                current = head;
            } else {
                current->next = newNode;
                current = current->next;
            }
        }

        return head;
    }
};