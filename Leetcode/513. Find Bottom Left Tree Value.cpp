//link
//https://leetcode.com/problems/find-bottom-left-tree-value/description/?envType=problem-list-v2&envId=binary-tree

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
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        queue<TreeNode*> q;
        int leftmost = root -> val;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                if(i == 0){
                    leftmost = frontNode -> val;
                }

                if(frontNode -> left){
                    q.push(frontNode -> left);

                }
                if(frontNode -> right){
                    q.push(frontNode -> right);
                }

            }

        }

        return leftmost;
    }
};