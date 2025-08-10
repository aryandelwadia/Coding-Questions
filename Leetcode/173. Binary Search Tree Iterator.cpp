//link
//https://leetcode.com/problems/binary-search-tree-iterator/description/

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
class BSTIterator {
public:
    int i;
    int n;
    vector<int> inorder;

    void in(TreeNode* root, vector<int>& inorder){
        if(root == NULL) return;

        in(root -> left, inorder);
        inorder.push_back(root -> val);
        in(root -> right, inorder);
    }

    BSTIterator(TreeNode* root) {
        i = 0;
        in(root, inorder);
        n = inorder.size();
    }
    
    int next() {
        return inorder[i++];
    }
    
    bool hasNext() {
        if(i < n) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */