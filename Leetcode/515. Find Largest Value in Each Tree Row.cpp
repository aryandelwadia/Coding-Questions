//link
//https://leetcode.com/problems/find-largest-value-in-each-tree-row/?envType=problem-list-v2&envId=binary-tree

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        map<int, int> nodes;
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                pair<int, TreeNode*> temp = q.front();
                int lvl = temp.first;
                TreeNode* frontNode = temp.second;
                q.pop();
                
                if(nodes.find(lvl) == nodes.end()){
                    nodes[lvl] = frontNode -> val;
                }
                else{
                    nodes[lvl] = max(nodes[lvl], frontNode -> val);
                }

                if(frontNode -> left){
                    q.push(make_pair(lvl + 1, frontNode -> left));
                }

                if(frontNode -> right){
                    q.push(make_pair(lvl + 1, frontNode -> right));
                }

            }
        }

        for(auto& i:nodes){
            ans.push_back(i.second);
        }

        return ans;
    }
};