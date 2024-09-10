//link
//https://leetcode.com/problems/binary-tree-tilt/description/?envType=problem-list-v2&envId=binary-tree

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
    int tilt(TreeNode* root, int &ans){
        if(root == NULL){
            return 0;
        }

        int left = tilt(root -> left, ans);
        int right = tilt(root -> right, ans);

        int diff = abs(left - right);
        ans += diff;

        return root -> val + left + right; 
    }

public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        tilt(root, ans);

        return ans;
    }
};