//link
//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=problem-list-v2&envId=binary-tree

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
    int findIndex(vector<int> arr, int n){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == n){
                return i;
            }
        }
        return -1;
    }

    TreeNode* binaryTree(vector<int> preorder, vector<int> inorder, int &preOrderIndex, int leftIndex, int rightIndex){
        if(preOrderIndex >= preorder.size() || leftIndex > rightIndex){
            return NULL;
        }

        int element = preorder[preOrderIndex++];
        TreeNode* temp = new TreeNode(element);
        int position = findIndex(inorder, element);

        temp -> left = binaryTree(preorder, inorder, preOrderIndex, leftIndex, position - 1);
        temp -> right = binaryTree(preorder, inorder, preOrderIndex, position + 1, rightIndex);

        return temp;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int leftIndex = 0;
        int rightIndex = preorder.size() - 1;
        return binaryTree(preorder, inorder, preOrderIndex, leftIndex, rightIndex);
    }
};