//link
//https://leetcode.com/problems/univalued-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

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
    bool solve(TreeNode* root, int n){
        if(root == NULL){
            return true;
        }

        if(root -> val != n){
            return false;
        }

        return solve(root -> left, n) && solve(root -> right, n);
    }

public:
    bool isUnivalTree(TreeNode* root) {
        return solve(root, root -> val);
    }
};