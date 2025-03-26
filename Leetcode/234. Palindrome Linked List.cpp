//link
//https://leetcode.com/problems/palindrome-linked-list

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
        bool isPalindrome(ListNode* head) {
            ListNode* s = head;
            ListNode* f = head;
            while(f->next != NULL && f->next->next != NULL){
                s = s->next;
                f = f->next->next;
            }
    
            ListNode* prev = NULL;
            ListNode* curr = s;
            ListNode* nex = curr->next;
    
            while(curr != NULL){
                nex = curr -> next;
                curr->next = prev;
                prev = curr;
                curr = nex;
            }
    
            while(head != NULL && prev != NULL){
                if(head->val != prev->val){
                    return false;
                }
    
                head = head -> next;
                prev = prev -> next;
            }
    
            return true;
        }
    };