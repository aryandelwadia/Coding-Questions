//link
//https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670

#include<bits/stdc++.h>

bool cycle(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node){
    queue<int> q;
    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = true;
    q.push(node);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto i: adj[frontNode]){
            if(visited[i] && i != parent[frontNode]){
                return true;
            }

            else if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = frontNode;
            }
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    unordered_map<int, list<int>> adj;

    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bool ans = cycle(adj, visited, i);
            if(ans){
                return "Yes";
            }
        }
    }

    return "No";
}
