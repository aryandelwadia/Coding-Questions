//link
//https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
    public:
      bool bfs(int node, vector<vector<int>>& adj, vector<bool> &visited){
          unordered_map<int, int> parent;
          visited[node] = true;
          parent[node] = -1;
          queue<int> q;
          q.push(node);
          
          while(!q.empty()){
              int front = q.front();
              q.pop();
              
              for(auto i : adj[front]){
                  if(visited[i] && i != parent[front]){
                      return true;
                  }
                  else if(!visited[i]){
                      parent[i] = front;
                      q.push(i);
                      visited[i] = true;
                  }
              }
          }
          
          return false;
      }
      
      bool isCycle(int V, vector<vector<int>>& edges) {
          // Code here
          vector<bool> visited(edges.size(), false);
          
          for(int i = 0; i < edges.size(); i++){
              if(!visited[i]){
                  bool cycle = bfs(i, edges, visited);
                  if(cycle){
                      return true;
                  }
              }
          }
          
          return false;
      }
  };