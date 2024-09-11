//link
//https://www.naukri.com/code360/problems/preorder-traversal-to-bst_893111

#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
BinaryTreeNode<int>* solve(vector<int> preorder, int min, int max, int &i){
    if(i >= preorder.size()){
        return NULL;
    }

    if(preorder[i] < min || preorder[i] > max){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root -> left = solve(preorder, min, root -> data, i);
    root -> right = solve(preorder, root -> data, max, i);

    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int i = 0;
    return solve(preorder, INT_MIN, INT_MAX, i);
}