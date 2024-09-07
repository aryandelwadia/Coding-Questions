//link
//https://leetcode.com/problems/path-sum-iii/?envType=problem-list-v2&envId=binary-tree

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
    void solve(TreeNode* root, int targetSum, int &count, vector<int> result){
        if(root == NULL){
            return;
        }

        result.push_back(root -> val);
        int size = result.size();
        long sum = 0;
        for(int i = size - 1; i >= 0; i--){
            sum += result[i];
            if(sum == targetSum){
                count++;
            } 
        }

        solve(root -> left, targetSum, count, result);
        solve(root -> right, targetSum, count, result);

        result.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        vector<int> result;
        solve(root, targetSum, count, result);
        return count;
    }
};