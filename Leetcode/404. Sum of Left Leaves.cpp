//link
//https://leetcode.com/problems/sum-of-left-leaves/description/?envType=problem-list-v2&envId=binary-tree

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

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();
            if(frontNode -> left){
                q.push(frontNode -> left);
                if(frontNode -> left -> left == NULL && frontNode -> left -> right == NULL){
                    sum += frontNode -> left -> val;
                }
            }
            

            if(frontNode -> right){
                q.push(frontNode -> right);
            }
        }

        return sum;
    }
};