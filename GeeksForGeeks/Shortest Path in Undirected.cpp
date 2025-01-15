//link
//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int> dist(adj.size(), INT_MAX);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto i : adj[front]){
                if(dist[front] + 1 < dist[i]){
                    dist[i] = dist[front] + 1;
                    q.push(i);
                }
            }
        }
        
        for(int i = 0; i < adj.size(); i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};