//link
//https://www.naukri.com/code360/problems/bridges-in-graph_893026

#include<bits/stdc++.h>

void dfs(unordered_map<int, list<int>> &adj, int node, int parent, int &timer, vector<int> &discovery, vector<int> &low, unordered_map<int, bool> &visited, vector<vector<int>> &ans){

    visited[node] = true;
    discovery[node] = low[node] = timer++;

    for(auto i: adj[node]){
        if(i == parent){
            continue;
        }
        if(!visited[i]){
            dfs(adj, i, node, timer, discovery, low, visited, ans);
            low[node] = min(low[node], low[i]);

            if(low[i] > discovery[node]){
                vector<int> a;
                a.push_back(node);
                a.push_back(i);
                ans.push_back(a);
            }
        }
        else{
            low[node] = min(low[node], discovery[i]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> discovery(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> visited;

    for(int i = 0; i < v; i++){
        discovery[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> ans;
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            dfs(adj, i, parent, timer, discovery, low, visited, ans);
        }
    }

    return ans;
}