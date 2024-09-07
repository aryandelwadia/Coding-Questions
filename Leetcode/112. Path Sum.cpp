//link
//https://leetcode.com/problems/path-sum/description/?envType=problem-list-v2&envId=binary-tree

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
    bool solve(TreeNode* root, int targetSum, int sum){
        if(root == NULL){
            return false;
        }
        if(root -> left == NULL && root -> right == NULL){
            sum += root -> val;
            if(sum == targetSum){
                return true;
            }
            else{
                return false;
            }
        }

        sum += root -> val;
        bool left = solve(root -> left, targetSum, sum);
        bool right = solve(root -> right, targetSum, sum);

        return (left || right);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return solve(root, targetSum, sum);
    }
};