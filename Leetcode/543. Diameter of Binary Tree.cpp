//link
//https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

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
    int solve(TreeNode* root, int &ans){
        if(root == NULL){
            return 0;
        }

        int left = solve(root -> left, ans);
        int right = solve(root -> right, ans);

        int dia = left + right;
        ans = max(ans, dia);

        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);

        return ans;
    }
};