//link
//https://www.naukri.com/code360/problems/count-leaf-nodes_893055

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
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
    
***********************************************************/

void inOrderTraversal(BinaryTreeNode<int> *root, int &count){
    if (root == NULL){
        return;
    }

    inOrderTraversal(root -> left, count);
    if(root -> left == NULL && root -> right == NULL){
        count++;
    }
    inOrderTraversal(root -> right, count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.

    int count = 0;

    inOrderTraversal(root, count);

    return count;
}