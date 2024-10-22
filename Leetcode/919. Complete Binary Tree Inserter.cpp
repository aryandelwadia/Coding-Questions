//link
//https://leetcode.com/problems/complete-binary-tree-inserter?envType=problem-list-v2&envId=binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class CBTInserter {
public:
    queue<TreeNode*> q;
    TreeNode *head = nullptr, *Ins = nullptr;

    CBTInserter(TreeNode* root) {

        head = root;
        q.push(head);

        while(1)
        {
            root = q.front();
            q.pop();
            Ins=root;

            if(root->left)q.push(root->left);
            else  break;    
            if(root->right)q.push(root->right);
            else  break;
        }
    
    }

    int insert(int val) {
        TreeNode *a = new TreeNode(val), *par=Ins;
        
        if(Ins->left){
            Ins->right=a;
            Ins=q.front(); q.pop();
        }
        else 
            Ins->left=a;
    
        q.push(a);
        return par->val;
    }

    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */