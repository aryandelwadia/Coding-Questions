//link
//https://www.geeksforgeeks.org/problems/construct-tree-1/1

// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    
    int find(vector<int>& inorder, int element, int n){
        for(int i = 0; i < n; i++){
            if(inorder[i] == element){
                return i;
            }
        }
        
        return -1;
    }
    
    Node* solve(vector<int> &inorder, vector<int> &preorder, int& index, int start, int end, int n){
        if(index >= n || start > end){
            return NULL;
        }
        
        int element = preorder[index];
        index++;
        Node* root = new Node(element);
        int pos = find(inorder, element, n);
        
        root -> left = solve(inorder, preorder, index, start, pos - 1, n);
        root -> right = solve(inorder, preorder, index, pos + 1, end, n);
        
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int index = 0;
        int n = inorder.size();
        Node* ans = solve(inorder, preorder, index, 0, n - 1, n);
        
        return ans;
    }
};