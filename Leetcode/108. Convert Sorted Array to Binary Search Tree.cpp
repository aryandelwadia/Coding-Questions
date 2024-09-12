//link
//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/?envType=problem-list-v2&envId=binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* solve(vector<int> nums, int s, int e){
        if(s > e){
            return NULL;
        }

        int mid = s + (e - s) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = solve(nums, s, mid - 1);
        root -> right = solve(nums, mid + 1, e);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        return solve(nums, s, e);
    }
};