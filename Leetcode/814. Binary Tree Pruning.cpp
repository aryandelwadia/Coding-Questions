//link
//https://leetcode.com/problems/binary-tree-pruning/?envType=problem-list-v2&envId=binary-tree

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
    bool solve(TreeNode* root){
        if(root == NULL){
            return false;
        }
        if(root -> left == NULL && root -> right == NULL){
            if(root -> val){
                return false;
            }
            return true;
        }

        bool left = solve(root -> left);
        bool right = solve(root -> right);

        if(left){
            root -> left = NULL;
        }
        if(right){
            root -> right = NULL;
        }

        if(root -> left == NULL && root -> right == NULL && root -> val == 0){
            return true;
        }

        return false;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
       bool b = solve(root);
       if(b){
        return NULL;
       }
       return root; 
    }
};