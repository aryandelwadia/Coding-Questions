//link
//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=problem-list-v2&envId=binary-tree

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

    TreeNode* binaryTree(vector<int> postorder, vector<int> inorder, int &postorderIndex, int leftIndex, int rightIndex){
        if(postorderIndex < 0 || leftIndex > rightIndex){
            return NULL;
        }

        int element = postorder[postorderIndex--];
        TreeNode* temp = new TreeNode(element);
        int position = findIndex(inorder, element);

        temp -> right = binaryTree(postorder, inorder, postorderIndex, position + 1, rightIndex);
        temp -> left = binaryTree(postorder, inorder, postorderIndex, leftIndex, position - 1);

        return temp;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = inorder.size() - 1;
        return binaryTree(postorder, inorder, postorderIndex, 0, inorder.size() - 1);
    }
};