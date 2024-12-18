//link
//https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.

    unordered_map<int, list<pair<int, int>> > adj;
    for(int i = 0; i < vec.size(); i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(vertices);
    for(int i = 0; i < vertices; i++){
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> s;
    dist[source] = 0;
    s.insert({0, source});

    while(!s.empty()){
        auto top = *(s.begin());
        s.erase(s.begin());

        int nodeDist = top.first;
        int node = top.second;

        for(auto i: adj[node]){
            if(nodeDist + i.second < dist[i.first]){
                auto record = s.find({dist[i.first], i.first});
                if(record != s.end()){
                    s.erase(record);
                }

                dist[i.first] = nodeDist + i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }

    return dist;
}
