//link
//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> nodes;
        queue<tuple<int, TreeNode*, int>> q;

        if (root) {
            q.push({0, root, 0});
        }

        while (!q.empty()) {
            auto [hd, node, level] = q.front();
            q.pop();
            
            nodes[hd].emplace_back(level, node->val);
            
            if (node->left) {
                q.push({hd - 1, node->left, level + 1});
            }
            if (node->right) {
                q.push({hd + 1, node->right, level + 1});
            }
        }

        vector<vector<int>> result;
        for (auto& [key, vec] : nodes) {
            sort(vec.begin(), vec.end());
            vector<int> column;
            for (const auto& p : vec) {
                column.push_back(p.second); 
            }
            result.push_back(column);
        }

        return result;
    }
};