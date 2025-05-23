//link
//https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        for(int i = 0; i < V - 1; i++){
            for(auto i : edges){
                int u = i[0];
                int v = i[1];
                int w = i[2];
                
                if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
                
            if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                return {-1};
            }
        }
        
        return dist;
    }
};