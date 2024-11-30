//link
//https://leetcode.com/problems/delete-node-in-a-bst?envType=problem-list-v2&envId=tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* find(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val > key) {
            root -> left = find(root->left, key);
        } else if (root->val < key) {
            root -> right = find(root->right, key);
        } else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* succ = root -> right;
            while (succ != NULL && succ->left != NULL) {
                succ = succ->left;
            }

            root->val = succ->val;
            root -> right = find(root->right, succ->val);
        }

        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return find(root, key);
    }
};