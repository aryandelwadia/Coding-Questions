//link
//https://leetcode.com/problems/path-sum-ii/description/?envType=problem-list-v2&envId=binary-tree

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
    void solve(TreeNode* root, int targetSum, int sum, vector<vector<int>> &ans, vector<int> &result){
        if(root == NULL){
            return;
        }

        sum += root -> val;
        result.push_back(root -> val);

        if(root -> left == NULL && root -> right == NULL){
            if(sum == targetSum){
                ans.push_back(result);
            }
        }
        solve(root -> left, targetSum, sum, ans, result);
        solve(root -> right, targetSum, sum, ans, result);
        result.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        vector<int> result;
        solve(root, targetSum, 0, ans, result);
        return ans;
    }
};