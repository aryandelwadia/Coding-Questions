//link
//https://leetcode.com/problems/print-binary-tree/?envType=problem-list-v2&envId=binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left_height = height(root->left);
        int right_height = height(root->right);
        return 1 + max(left_height, right_height);
    }

    vector<vector<string>> printTree(TreeNode* root) {

        int h = height(root);
        h--;
        int n = h + 1;
        int m = pow(2, h + 1) - 1;
        vector<vector<string>> res(n, vector<string>(m, ""));
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, (m - 1) / 2}});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int r = curr.second.first;
            int c = curr.second.second;
            TreeNode* curr_node = curr.first;

            res[r][c] = to_string(curr_node->val);

            if (curr_node->left) {
                q.push({curr_node->left, {r + 1, c - pow(2, h - 1 - r)}});
            }

            if (curr_node->right) {
                q.push({curr_node->right, {r + 1, c + pow(2, h - 1 - r)}});
            }
        }

        return res;
    }
};