//link
//https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
    public:
      void dfs(vector<vector<int>>& adj, vector<int>& ans, vector<int>& visited, int node){
          visited[node] = 1;
          ans.push_back(node);
          for(auto i : adj[node]){
              if(!visited[i]){
                  dfs(adj, ans, visited, i);
              }
          }
      }
    
      vector<int> dfs(vector<vector<int>>& adj) {
          // Code here
          vector<int> ans;
          vector<int> visited(adj.size(), 0);
          dfs(adj, ans, visited, 0);
          return ans;
      }
  };