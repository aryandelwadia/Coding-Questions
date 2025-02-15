//link
//https://www.naukri.com/code360/problems/prim-s-mst_1095633

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int, list<pair<int, int>> > adj;
    for(int i = 0; i < g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> keys(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for(int i = 1; i <= n; i++){
        keys[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    keys[1] = 0;
    parent[1] = -1;

    for(int i = 1; i < n; i++){
        
        int mini = INT_MAX;
        int u;

        for(int v = 1; v <= n; v++){
            if(!mst[v] && keys[v] < mini){
                mini = keys[v];
                u = v;
            }
        }

        mst[u] = true;

        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(!mst[v] && w < keys[v]){
                keys[v] = w;
                parent[v] = u;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans;

    for(int i = 2; i <= n; i++){
        ans.push_back({{parent[i], i}, keys[i]});
    }

    return ans;
}
