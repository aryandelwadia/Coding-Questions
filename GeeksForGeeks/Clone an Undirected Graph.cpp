//link
//https://www.geeksforgeeks.org/problems/clone-graph/1

class Solution {
    public:
      Node* cloneGraph(Node* node) {
          // code here
          unordered_map<Node*, Node*> cloneMap;
          queue<Node*> q;
          q.push(node);
          
          cloneMap[node] = new Node(node->val);
          
          while(!q.empty()){
              Node* front = q.front();
              q.pop();
              
              for(auto nbr : front -> neighbors){
                  if(cloneMap.find(nbr) == cloneMap.end()){
                      cloneMap[nbr] = new Node(nbr -> val);
                      q.push(nbr);
                  }
                  
                  cloneMap[front] -> neighbors.push_back(cloneMap[nbr]);
              }
          }
          
          return cloneMap[node];
      }
  };