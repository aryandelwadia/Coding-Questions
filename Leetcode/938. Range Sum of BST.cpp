//link
//https://leetcode.com/problems/range-sum-of-bst/description/?envType=problem-list-v2&envId=binary-tree

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> in;
        inorder(root, in);

        int l = 0;
        int r = 0;

        for(int i = 0; i < in.size(); i++){
            if(in[i] == low){
                l = i;
            }
            if(in[i] == high){
                r = i;
            }
        }
        int sum = 0;
        for(int i = l; i <= r; i++){
            sum += in[i];
        }

        return sum;
    }
};