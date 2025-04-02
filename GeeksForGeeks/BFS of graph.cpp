//link
//https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
    public:
      // Function to return Breadth First Traversal of given graph.
      vector<int> bfs(vector<vector<int>> &adj) {
          // Code here
          vector<int> visited(adj.size(), 0);
          vector<int> ans;
          queue<int> q;
          
          q.push(0);
          visited[0] = 1;
          while(!q.empty()){
              int front = q.front();
              q.pop();
              ans.push_back(front);
              for(auto i : adj[front]){
                  if(visited[i] == 0){
                      q.push(i);
                      visited[i] = 1;
                  }
              }
          }
          
          return ans;
      }
  };