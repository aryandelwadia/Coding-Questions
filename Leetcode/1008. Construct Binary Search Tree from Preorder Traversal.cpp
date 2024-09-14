//link
//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/?envType=problem-list-v2&envId=binary-tree

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
    TreeNode* insert(TreeNode* &root, int n){
        if(root == NULL){
            return new TreeNode(n);
        }

        if(root -> val > n){
            root -> left = insert(root -> left, n);
        }
        if(root -> val < n){
            root -> right = insert(root -> right, n);
        }

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 1){
            return new TreeNode(preorder[0]);
        }

        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); i++){
            insert(root, preorder[i]);
        }

        return root;
    }
};