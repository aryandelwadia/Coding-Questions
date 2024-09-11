//link
//https://www.naukri.com/code360/problems/flatten-bst-to-a-sorted-list_1169459

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorderTraversal(TreeNode<int>* root, vector<int>& ans){
    if(root == NULL){
        return;
    }

    inorderTraversal(root -> left, ans);
    ans.push_back(root -> data);
    inorderTraversal(root -> right, ans);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    if(root == NULL){
        return NULL;
    }

    vector<int> inorder;
    inorderTraversal(root, inorder);

    TreeNode<int>* ans = new TreeNode<int>(inorder[0]);
    ans -> left = NULL;
    TreeNode<int>* curr = ans;

    for(int i = 1; i < inorder.size(); i++){
        TreeNode<int>* temp = new TreeNode<int>(inorder[i]);
        curr -> right = temp;
        curr -> left = NULL;
        curr = curr -> right;
    }

    curr -> left = NULL;
    curr -> right = NULL;

    return ans;
}
