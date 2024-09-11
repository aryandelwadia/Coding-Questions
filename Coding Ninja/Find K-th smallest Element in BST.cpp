//link
//https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

int solve(BinaryTreeNode<int>* root, int k, int &i){
    if(root == NULL){
        return -1;
    }

    int left = solve(root -> left, k, i);
    if(left != -1){
        return left;
    }

    i++;
    if(i == k){
        return root -> data;
    }

    return solve(root -> right, k , i);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i = 0;
    return solve(root, k , i);
}