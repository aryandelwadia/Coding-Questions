//link
//https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

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
private:
    void inOrder(TreeNode* root, set<int> &s){
        if(root == NULL){
            return;
        }

        inOrder(root -> left, s);
        s.insert(root -> val);
        inOrder(root -> right, s);
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        int ans;

        inOrder(root, s);

        if (s.size() < 2) {
            return -1;  
        }
        
        auto it = s.begin();
        advance(it, 1);
        return *it;
    }
};