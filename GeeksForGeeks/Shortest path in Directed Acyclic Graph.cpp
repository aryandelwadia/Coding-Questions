//link
//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution {
  private:
    void dfs(int node, vector<int> &visited, stack<int> &st, unordered_map<int, list<pair<int, int>>> &adj){
        visited[node] = true;
        
        for(auto i : adj[node]){
            if(!visited[i.first]){
                dfs(i.first, visited, st, adj);
            }
        }
        st.push(node);
    }
  
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
        }
        
        vector<int> topo;
        stack<int> st;
        vector<int> visited(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, visited, st, adj);
            }
        }
        
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(dist[top] != INT_MAX){
                for(auto i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
        
        for(int i = 0; i < V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};