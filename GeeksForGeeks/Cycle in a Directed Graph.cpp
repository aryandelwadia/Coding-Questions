//link
//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    bool dfs(int node, vector<bool> &visited, vector<bool> &dfsVisited, vector<vector<int>> &adj){
        visited[node] = true;
        dfsVisited[node] = true;
                
        for(auto i : adj[node]){
            if(visited[i] && dfsVisited[i]){
                return true;
            }
            else if(!visited[i]){
                bool cycle = dfs(i, visited, dfsVisited, adj);
                if(cycle){
                    return true;
                }
            }
        }
        dfsVisited[node] = false;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> dfsVisited(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bool cycle = dfs(i, visited, dfsVisited, adj);
                if(cycle){
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends