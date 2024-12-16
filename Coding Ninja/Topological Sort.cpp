//link
//https://www.naukri.com/code360/problems/topological-sort_982938

#include <bits/stdc++.h> 
void toposort(unordered_map<int, list<int>> &adj, unordered_map<int, int> &visited, stack<int> &st, int node){
    visited[node] = true;

    for(auto i: adj[node]){
        if(!visited[i]){
            toposort(adj, visited, st, i);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    unordered_map<int, list<int>> adj;
    for(int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, int> visited;
    stack<int> st;
    vector<int> ans;

    for(int i = 0; i < v; i++){
        if(!visited[i]){
            toposort(adj, visited, st, i);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}