//link
//https://leetcode.com/problems/binary-tree-right-side-view/?envType=problem-list-v2&envId=binary-tree

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
    void solve(TreeNode* root, vector<int> &ans, int lvl){
        if(root == NULL){
            return;
        }

        if(ans.size() == lvl){
            ans.push_back(root -> val);
        }

        solve(root -> right, ans, lvl + 1);
        solve(root -> left, ans, lvl + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};