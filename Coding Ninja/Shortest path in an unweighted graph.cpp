//link
//https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297

#include <bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here

	unordered_map<int, list<int>> adj;
	for(int i = 0; i < edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;
	queue<int> q;
	q.push(s);
	parent[s] = -1;
	visited[s] = true;

	while(!q.empty()){
		int frontNode = q.front();
		q.pop();
		
		for(auto i: adj[frontNode]){
			if(!visited[i]){
				visited[i] = true;
				parent[i] = frontNode;
				q.push(i);
			}
		}
	}

	vector<int> ans;
	ans.push_back(t);
	int curr = t;

	while(curr != s){
		curr = parent[curr];
		ans.push_back(curr);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
