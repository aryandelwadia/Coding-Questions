//link
//https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1

class Solution {
    public:
      bool dfs(int node, vector<bool> &vis,unordered_map<int, list<int>>& adj,int &find_node){
          vis[node] = 1;
          if(node==find_node) return 1;
          for(auto i : adj[node]){
              if(i!=-1 && !vis[i]){
                  bool isPresent = dfs(i,vis,adj,find_node);
                  if(isPresent) return 1;
              }
          }
          return 0;
      }
    
      bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
          // Code here
          unordered_map<int, list<int>> adj;
          for(int i = 0; i < edges.size(); i++){
              int u = edges[i][0];
              int v = edges[i][1];
              
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
          
          for(auto &i : adj[c]){
              if(i==d){
                  i = -1;
                  break;
              }
          }
          for(auto &i : adj[d]){
              if(i==c){
                  i = -1;
                  break;
              }
          }
          
          vector<bool> vis(V); 
          bool find = dfs(c, vis, adj, d);
          
          if(find) return 0;
          else return 1;
      }
  };