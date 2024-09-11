//link
//https://www.naukri.com/code360/problems/two-sum-in-a-bst_1062631

#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
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
    
};
***************/
void solve(BinaryTreeNode<int>* root, vector<int> &inorder){
    if(root == NULL){
        return;
    }

    solve(root -> left, inorder);
    inorder.push_back(root -> data);
    solve(root -> right, inorder);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> inorder;
    solve(root, inorder);

    int i = 0;
    int j = inorder.size() - 1;

    while(i < j){
        if(inorder[i] + inorder[j] == target){
            return true;
        }
        else if(inorder[i] + inorder[j] > target){
            j--;
        }
        else{
            i++;
        }
    }

    return false;
}