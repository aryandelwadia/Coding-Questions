//link
//https://www.naukri.com/code360/problems/h_920474

/*************************************************************

    Following is the Binary Tree node structure:

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
void inorder(TreeNode* root, vector<int> &in1){
    if(root == NULL){
        return;
    }

    inorder(root -> left, in1);
    in1.push_back(root -> data);
    inorder(root -> right, in1);
}

vector<int> mergeArray(vector<int> arr1, vector<int> arr2){
    int i = 0, j = 0;
    vector<int> arr3;

    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            arr3.push_back(arr1[i]);
            i++;
        }
        else{
            arr3.push_back(arr2[j]);
            j++;
        }
    }

    while(i < arr1.size()){
        arr3.push_back(arr1[i]);
        i++;
    }
    while(j < arr2.size()){
        arr3.push_back(arr2[j]);
        j++;
    }

    return arr3;
}

TreeNode* solve(vector<int> inorder, int start, int end){
    if(start > end){
        return NULL;
    }

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(inorder[mid]);


    root -> left = solve(inorder, start, mid - 1);
    root -> right = solve(inorder, mid + 1, end);

    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> in1;
    vector<int> in2;

    inorder(root1, in1);
    inorder(root2, in2);

    vector<int> arr3;
    arr3 = mergeArray(in1, in2);
    return arr3;
    // int s = 0;
    // int e = arr3.size();

    // solve(arr3, s, e);

    // TreeNode* bst = solve(arr3, s, e);
    // vector<int> ans;
    // inorder(bst, ans);
    // return ans;
}