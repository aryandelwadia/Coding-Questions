//link
//https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=problem-list-v2&envId=binary-tree

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
    void solve(TreeNode* root, int &ans, int num){
        if(root == NULL){
            return;
        }
        num = num * 10 + root -> val;

        if(root -> left == NULL && root -> right == NULL){
            ans += num;
            return;
        }

        solve(root -> left, ans, num);
        solve(root -> right, ans, num);
    }

public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int ans = 0;
        solve(root, ans, 0);
        return ans;
    }
};