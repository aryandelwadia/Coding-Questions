//link
//https://leetcode.com/problems/count-complete-tree-nodes/description/?envType=problem-list-v2&envId=binary-tree

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
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int count = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();
            count++;
            if(frontNode -> left){
                q.push(frontNode -> left);
            }
            if(frontNode -> right){
                q.push(frontNode -> right);
            }
        }

        return count;
    }
};