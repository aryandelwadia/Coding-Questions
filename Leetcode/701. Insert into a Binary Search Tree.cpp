//link
//https://leetcode.com/problems/insert-into-a-binary-search-tree/description/?envType=problem-list-v2&envId=binary-tree

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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* ans = new TreeNode(val);
            return ans;
        }

        if (root->val < val && root->right == NULL) {
            TreeNode* ans = new TreeNode(val);
            root->right = ans;
            return root;
        }

        if (root->val > val && root->left == NULL) {
            TreeNode* ans = new TreeNode(val);
            root->left = ans;
            return root;
        }

        if (root->left == NULL && root->right == NULL) {
            TreeNode* ans = new TreeNode(val);
            if (val > root->val) {
                root->right = ans;
            }
            if (val < root->val) {
                root->left = ans;
            }
            return root;
        }

        if (val < root->val)
            insertIntoBST(root->left, val);
        else if (val > root->val)
            insertIntoBST(root->right, val);

        return root;
    }
};