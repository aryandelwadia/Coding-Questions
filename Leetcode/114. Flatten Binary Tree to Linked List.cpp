//link
//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/?envType=problem-list-v2&envId=binary-tree

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
    void flatten(TreeNode* root, TreeNode* &prev){
        if(root == NULL){
            return;
        }

        if(prev){
            prev -> right = root;
        }

        prev = root;

        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        root -> left = NULL;

        flatten(left, prev);
        flatten(right, prev);
    }

public:
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }

        TreeNode* prev = nullptr;
        flatten(root, prev);
    }
};