//link
//https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ans = new ListNode(-1);
        ListNode *curr = head -> next;
        ListNode *temp = ans;
        long long sum = 0;

        while(curr != NULL){
            if(curr -> val == 0){
                ListNode *newNode = new ListNode(sum);
                temp -> next = newNode;
                temp = temp -> next;
                sum = 0;
                curr = curr -> next;
            }
            else{
                sum += curr -> val;
                curr = curr -> next; 
            }
        }

        return ans -> next;
    }
};