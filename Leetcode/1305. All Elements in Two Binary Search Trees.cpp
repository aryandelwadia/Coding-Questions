//link
//https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/?envType=problem-list-v2&envId=binary-tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> merge(vector<int> v1, vector<int> v2){
        vector<int> ans;
        int i = 0;
        int j = 0;

        while(i < v1.size() && j < v2.size()){
            if(v1[i] < v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
            else{
                ans.push_back(v2[j]);
                j++;
            }
        }

        while(i < v1.size()){
            ans.push_back(v1[i]);
            i++;
        }
        while(j < v2.size()){
            ans.push_back(v2[j]);
            j++;
        }

        return ans;
    }

    void inorder(TreeNode* root, vector<int> &in){
        if(root == NULL){
            return;
        }

        inorder(root -> left, in);
        in.push_back(root -> val);
        inorder(root -> right, in);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> in1;
        vector<int> in2;

        inorder(root1, in1);
        inorder(root2, in2);

        return merge(in1, in2);
    }
};