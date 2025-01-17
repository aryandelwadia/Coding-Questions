//link
//https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, list<pair<int, int>>> adj;

        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        vector<int > time(n + 1, INT_MAX);
        time[k] = 0;

        queue<int> q;
        q.push(k);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto i : adj[front]){
                if(time[front] + i.second < time[i.first]){
                    time[i.first] = time[front] + i.second;
                    q.push(i.first);
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(time[i] == INT_MAX){
                return -1;
            }
            ans = max(ans, time[i]);
        }

        return ans;
    }
};