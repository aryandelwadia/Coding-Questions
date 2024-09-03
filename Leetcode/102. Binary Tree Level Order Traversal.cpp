//link
//https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=problem-list-v2&envId=binary-tree

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> result;
            for(int i = 0; i < n; i++){
                TreeNode *frontNode = q.front();
                q.pop();
                if(frontNode -> left != NULL){
                    q.push(frontNode -> left);
                }
                if(frontNode -> right != NULL){
                    q.push(frontNode -> right);
                }
                result.push_back(frontNode -> val);
            }

            ans.push_back(result);
        }

        return ans;
    }
};