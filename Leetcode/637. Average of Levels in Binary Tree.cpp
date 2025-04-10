//link
//https://leetcode.com/problems/average-of-levels-in-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                sum += frontNode -> val;

                if(frontNode -> left){
                    q.push(frontNode -> left);
                }
                if(frontNode -> right){
                    q.push(frontNode -> right);
                }
            }
            double avg = static_cast<double>(sum) / size;
            ans.push_back(avg);
        }

        return ans;
    }
};