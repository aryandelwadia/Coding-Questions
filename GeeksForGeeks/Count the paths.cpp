//link
//https://www.geeksforgeeks.org/problems/count-the-paths4332/1

class Solution {
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> indegree(V, 0);
        for(auto &e : edges) {
            indegree[e[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; ++i) {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for(int v : adj[u]) {
                if(--indegree[v] == 0)
                    q.push(v);
            }
        }

        vector<int> dp(V, 0);
        dp[src] = 1;

        for(int u : topo) {
            for(int v : adj[u]) {
                dp[v] += dp[u];
            }
        }

        return dp[dest];
    }
};