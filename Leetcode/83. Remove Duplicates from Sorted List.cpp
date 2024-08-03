//Link
//https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> nums;

        ListNode *curr = head;

        while(curr != NULL){
            nums.insert(curr -> val);
            curr = curr -> next;
        }

        ListNode *headNode = new ListNode(-1);
        curr = headNode;

        for(auto n : nums){
            ListNode *newNode = new ListNode(n);
            curr -> next = newNode;
            curr = curr -> next;
        }

        return headNode->next;
    }
};