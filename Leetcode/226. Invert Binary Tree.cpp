//link
//https://leetcode.com/problems/invert-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

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
    void invert(TreeNode* root){
        if(root == NULL){
            return;
        }

        TreeNode* right = root -> right;
        root -> right = root -> left;
        root -> left = right;

        invert(root -> left);
        invert(root -> right);
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};