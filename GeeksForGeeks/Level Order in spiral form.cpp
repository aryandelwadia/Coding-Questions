//link
//https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        bool direction = false;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> result(size);
            for(int i = 0; i < size; i++){
                Node* frontNode = q.front();
                q.pop();
                
                int index = direction ? i : size - i - 1;
                result[index] = frontNode -> data;
                
                if(frontNode -> left){
                    q.push(frontNode -> left);
                }
                if(frontNode -> right){
                    q.push(frontNode -> right);
                }
            }
            
            direction = !direction;
            for(auto i : result){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};