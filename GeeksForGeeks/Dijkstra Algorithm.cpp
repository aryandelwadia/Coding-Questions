//link
//https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        
        set<pair<int, int>> s;
        vector<int> dist(adj.size(), INT_MAX);
        dist[src] = 0;
        
        s.insert({0, src});
        
        while(!s.empty()){
            auto i = *(s.begin());
            int node = i.second;
            int w = i.first;
            s.erase(i);
            
            for(auto it : adj[node]){
                int n = it.first;
                int w2 = it.second;
                if(w + w2 < dist[n]){
                    if(dist[n] != INT_MAX){
                        s.erase({dist[n], n});
                    }
                    dist[n] = w + w2;
                    s.insert({dist[n], n});
                }
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends