//link
//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
    public:
      bool dfs(unordered_map<int, list<int>>& adj, vector<bool>& visited, vector<bool>& dfsVisited, int node){
          visited[node] = true;
          dfsVisited[node] = true;
          
          for(auto nbr : adj[node]){
              if(visited[nbr] && dfsVisited[nbr]){
                  return true;
              }
              else if(!visited[nbr]){
                  bool cycle = dfs(adj, visited, dfsVisited, nbr);
                  if(cycle){
                      return true;
                  }
              }
          }
          
          dfsVisited[node] = false;
          return false;
      }
      
      bool isCyclic(int V, vector<vector<int>> &edges) {
          // code here
          unordered_map<int, list<int>> adj;
          for(int i = 0; i < edges.size(); i++){
              int u = edges[i][0];
              int v = edges[i][1];
              
              adj[u].push_back(v);
          }
          
          vector<bool> visited(V, false);
          vector<bool> dfsVisited(V, false);
          
          for(int i = 0; i < V; i++){
              if(!visited[i]){
                  bool cycle = dfs(adj, visited, dfsVisited, i);
                  if(cycle){
                      return true;
                  }
              }
          }
          
          return false;
      }
  };