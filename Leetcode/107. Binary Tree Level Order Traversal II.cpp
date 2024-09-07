//link
//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/?envType=problem-list-v2&envId=binary-tree

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        stack<vector<int>> st;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> result;
            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                result.push_back(frontNode -> val);

                if(frontNode -> left){
                    q.push(frontNode -> left);
                }
                if(frontNode -> right){
                    q.push(frontNode -> right);
                }
            }
            st.push(result);
        }

        while(!st.empty()){
            vector<int> element = st.top();
            st.pop();
            ans.push_back(element);
        }

        return ans;
    }
};