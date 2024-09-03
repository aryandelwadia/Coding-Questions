//link
//https://leetcode.com/problems/balanced-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

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

    pair<bool, int> balanceFaster(TreeNode* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> left = balanceFaster(root -> left);
        pair<bool, int> right = balanceFaster(root -> right);

        bool leftCheck = left.first;
        bool rightCheck = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        if(leftCheck && rightCheck && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }

        return ans;
    }

public:
    bool isBalanced(TreeNode* root) {
        return balanceFaster(root).first;
    }
};