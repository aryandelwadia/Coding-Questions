//link
//https://leetcode.com/problems/smallest-string-starting-from-leaf?envType=problem-list-v2&envId=binary-tree

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
    void inorder(TreeNode* root, string str, vector<string>& list) {
        if(root == nullptr) return;
        
        string temp = (char)(97+root->val) + str;

        if(root->left == nullptr && root->right == nullptr) list.push_back(temp);

        inorder(root->left, temp, list);
        inorder(root->right, temp, list);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> list;
        string str = "";
        inorder(root, str, list);

        sort(list.begin(), list.end());

        return list[0];
    }
};