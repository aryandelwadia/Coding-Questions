//link
//https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151

#include<bits/stdc++.h>

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, stack<int> &st){
	vis[node] = true;

	for(auto nbr: adj[node]){
		if(!vis[nbr]){
			dfs(nbr, adj, vis, st);
		}
	}

	st.push(node);
}

void revDfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis){
	vis[node] = true;
	for(auto nbr : adj[node]){
		if(!vis[nbr]){
			revDfs(nbr, adj, vis);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	unordered_map<int, list<int>> adj;

	for(int i = 0; i < edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	stack<int> st;
	unordered_map<int, bool> vis;
	for(int i = 0; i < v; i++){
		if(!vis[i]){
			dfs(i, adj, vis, st);
		}
	}

	unordered_map<int, list<int>> transpose;
	for(int i = 0; i < v; i++){
		vis[i] = false;
		for(auto nbr : adj[i]){
			transpose[nbr].push_back(i);
		}
	}

	int count = 0;
	while(!st.empty()){
		int top = st.top();
		st.pop();
		if(!vis[top]){
			count++;
			revDfs(top, transpose, vis);
		}
	}

	return count;
}