//link
//https://leetcode.com/problems/increasing-order-search-tree?envType=problem-list-v2&envId=binary-tree

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
    void inorder(TreeNode* root, queue<TreeNode*> &q){
        if(root == NULL){
            return;
        }

        inorder(root -> left, q);
        q.push(root);
        inorder(root -> right, q);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        queue<TreeNode*> q;
        inorder(root, q);
        root = q.front();
        q.pop();
        TreeNode *temp = root;
        
        while(!q.empty()){
            TreeNode* next = q.front();
            q.pop();
            temp -> left = NULL;
            temp -> right = next;
            temp = next;
        }

        temp -> left = NULL;
        temp -> right = NULL;

        return root;
    }
};