//link
//https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
public:
    unordered_map<int, int> inorder_map;

    Node* solve(vector<int>& inorder, vector<int>& postorder, int& index, int start, int end) {
        if (start > end) return NULL;
        
        int element = postorder[index];
        index--;
        
        Node* root = new Node(element);
        
        int pos = inorder_map[element];
        root->right = solve(inorder, postorder, index, pos + 1, end);
        root->left = solve(inorder, postorder, index, start, pos - 1);
        
        return root;
    }
    
    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        
        for (int i = 0; i < n; i++) {
            inorder_map[inorder[i]] = i;
        }
        
        int index = n - 1;
        return solve(inorder, postorder, index, 0, n - 1);
    }
};