//link
//https://leetcode.com/problems/add-one-row-to-tree/?envType=problem-list-v2&envId=binary-tree

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
    void solve(TreeNode* root, int val, int depth, int curr){
        if(root == NULL){
            return;
        }
        if(curr + 1 == depth){
            TreeNode* val1 = new TreeNode(val);
            TreeNode* val2 = new TreeNode(val);
            val1 -> left = root -> left;
            val2 -> right = root -> right;
            root -> left = val1;
            root -> right = val2;
            return;
        }

        solve(root -> left, val , depth, curr + 1);
        solve(root -> right, val , depth, curr + 1);
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp -> left = root;
            return temp;
        }

        solve(root, val, depth, 1);
        return root;
    }
};


