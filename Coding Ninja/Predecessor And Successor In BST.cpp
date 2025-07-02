//link
//https://www.naukri.com/code360/problems/_893049

/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode* temp = root;
    int pred = -1; 
    int succ = -1;

    while (temp != nullptr && temp->data != key) {
        if (temp->data > key) {
            succ = temp->data;
            temp = temp->left;
        } else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    if (temp == nullptr) {
        return {pred, succ};
    }

    TreeNode* leftTree = temp->left;
    while (leftTree != nullptr) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    TreeNode* rightTree = temp->right;
    while (rightTree != nullptr) {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    
    return {pred, succ};
}
