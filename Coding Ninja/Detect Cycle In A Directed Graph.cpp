//link
//https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626

#include<bits/stdc++.h>

bool cycle(unordered_map<int, list<int>> &adj, unordered_map<int, int> &visited, unordered_map<int, int> &dfsVisited, int node){

  visited[node] = true;
  dfsVisited[node] = true;

  for(auto i: adj[node]){
    if(!visited[i]){
      bool detect = cycle(adj, visited, dfsVisited, i);
      if(detect){
        return true;
      }
    }
    else if(dfsVisited[i]){
      return true;
    }
  }

  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  unordered_map<int, list<int>> adj;

  for(int i = 0; i < edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int, int> visited;
  unordered_map<int, int> dfsVisited;

  for(int i = 1; i <= n; i++){
    if(!visited[i]){
      bool ans = cycle(adj, visited, dfsVisited, i);
      if(ans){
        return 1;
      }
    }
  }

  return 0;
}