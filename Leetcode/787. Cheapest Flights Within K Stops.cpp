//link
//https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        queue<pair<int, pair<int, int> > > q;
        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            int stops = front.first;
            int node = front.second.first;
            int cost = front.second.second;
            if(stops > k){
                continue;
            }

            for(auto i : adj[node]){
                if(cost + i.second <= dist[i.first] && stops <= k){
                    dist[i.first] = cost + i.second;
                    q.push({stops + 1, {i.first, dist[i.first]}});
                }
            }
        }

        if(dist[dst] == INT_MAX){
            return -1;
        }

        return dist[dst];
    }
};