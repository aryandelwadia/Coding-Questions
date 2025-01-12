//link
//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  private:
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
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        vector<bool> visited(adj.size(), false);
        
        for(int i = 0; i < adj.size(); i++){
            if(!visited[i]){
                bool cycle = bfs(i, adj, visited);
                if(cycle){
                    return true;
                }
            }
        }
        
        return false;
    }
};