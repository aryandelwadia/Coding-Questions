//link
//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

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
public:
    int maxLevelSum(TreeNode* root) {
        int maxSumLvl = 0;
        int maxSum = INT_MIN;
        int currLvl = 1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int currsum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                currsum += frontNode -> val;
                if(frontNode -> left){
                    q.push(frontNode -> left);
                }
                if(frontNode -> right){
                    q.push(frontNode -> right);
                }
            }

            if(currsum > maxSum){
                maxSum = currsum;
                maxSumLvl = currLvl;
            }
            currLvl++;
        }

        return maxSumLvl;
    }
};