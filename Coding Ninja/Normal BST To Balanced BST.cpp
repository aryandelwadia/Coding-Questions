//link
//https://www.naukri.com/code360/problems/normal-bst-to-balanced-bst_920472

/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorderTraversal(TreeNode<int>* root, vector<int> &ans){
    if(root == NULL){
        return;
    }

    inorderTraversal(root -> left, ans);
    ans.push_back(root -> data);
    inorderTraversal(root -> right, ans);
}

TreeNode<int>* solve(vector<int> inorder, int start, int end){
    if(start > end){
        return NULL;
    }

    int mid = start + (end - start) / 2;
    TreeNode<int>* root = new TreeNode<int>(inorder[mid]);


    root -> left = solve(inorder, start, mid - 1);
    root -> right = solve(inorder, mid + 1, end);

    return root;
}


TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    if(root == NULL){
        return NULL;
    }

    vector<int> inorder;
    inorderTraversal(root, inorder);

    return solve(inorder, 0, inorder.size() - 1);
}
