//link
//https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        Node* pre = NULL;
        Node* suc = NULL;
        
        Node* curr = root;
        
        while(curr != NULL){
            if(curr -> data < key){
                pre = curr;
                curr = curr -> right;
            }
            else{
                curr = curr -> left;
            }
        }
        
        curr = root;
        
        while(curr != NULL){
            if(curr -> data > key){
                suc = curr;
                curr = curr -> left;
            }
            else{
                curr = curr -> right;
            }
        }
        
        ans.push_back(pre);
        ans.push_back(suc);
        
        return ans;
    }
};