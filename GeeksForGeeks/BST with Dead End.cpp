//link
//https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool solve(Node* root, int mini, int maxi){
        if(root == NULL){
            return false;
        }
        
        if(root -> left == NULL && root -> right == NULL && mini == maxi){
            return true;
        }
        
        bool left = solve(root -> left, mini, root -> data - 1);
        bool right = solve(root -> right, root -> data + 1, maxi);
        
        return (left || right);
    }
  
    bool isDeadEnd(Node *root) {
        // Code here
        return solve(root, 1, INT_MAX);
    }
};