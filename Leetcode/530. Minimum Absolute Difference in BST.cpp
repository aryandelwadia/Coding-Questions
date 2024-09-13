//link
//https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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
    void inorder(TreeNode* root, vector<int> &in){
        if(root == NULL){
            return;
        }

        inorder(root -> left, in);
        in.push_back(root -> val);
        inorder(root -> right, in);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> in;
        inorder(root, in);

        int diff = INT_MAX;
        for(int i = 0; i < in.size() - 1; i++){
            diff = min(diff, in[i + 1] - in[i]);
        }

        return diff;
    }
};