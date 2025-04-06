//link
//https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
    public:
      void dfs(unordered_map<int, list<int>>& adj, vector<int>& visited, stack<int>& st, int node){
          visited[node] = true;
          
          for(auto nbr : adj[node]){
              if(visited[nbr] == 0){
                  dfs(adj, visited, st, nbr);
              }
          }
          st.push(node);
      }
      
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
          // code here
          unordered_map<int, list<int>> adj;
          for(int i = 0; i < edges.size(); i++){
              int u = edges[i][0];
              int v = edges[i][1];
              
              adj[u].push_back(v);
          }
          
          stack<int> st;
          vector<int> visited(V, 0);
          for(int i = 0; i < V; i++){
              if(visited[i] == 0){
                  dfs(adj, visited, st, i);
              }
          }
          
          vector<int> ans;
          while(!st.empty()){
              ans.push_back(st.top());
              st.pop();
          }
          
          return ans;
      }
  };