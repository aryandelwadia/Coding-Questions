//link
//https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree?envType=problem-list-v2&envId=binary-tree

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

    void changeval(TreeNode* root, vector<int> &in, int &i){
        if(root == NULL){
            return;
        }

        changeval(root -> left, in, i);
        root -> val = in[i];
        i++;
        changeval(root -> right, in, i);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> in;

        inorder(root, in);
        int sum = 0;
        for(int i = in.size() - 1; i >= 0; i--){
            sum += in[i];
            in[i] = sum;
        }
        int i = 0;
        changeval(root, in, i);

        return root;
    }
};