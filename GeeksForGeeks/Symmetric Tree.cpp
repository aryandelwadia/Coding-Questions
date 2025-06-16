//link
//https://www.geeksforgeeks.org/problems/symmetric-tree/1

/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool solve(Node* n1, Node* n2){
        if(n1 == NULL && n2 == NULL){
            return true;
        }
        if(n1 == NULL && n2 != NULL){
            return false;
        }
        if(n1 != NULL && n2 == NULL){
            return false;
        }
        if(n1 -> data != n2 -> data){
            return false;
        }
        
        bool left = solve(n1 -> left, n2 -> right);
        bool right = solve(n1 -> right, n2 -> left);
        
        return left && right;
    }
  
    bool isSymmetric(Node* root) {
        // Code here
        return solve(root -> left, root -> right);
    }
};