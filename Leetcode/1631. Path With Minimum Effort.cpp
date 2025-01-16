//link
//https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();

            int diff = front.first;
            int r = front.second.first;
            int c = front.second.second;

            if(r == m - 1 && c == n - 1){
                return diff;
            }

            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int newdiff = max(abs(heights[nr][nc] - heights[r][c]), diff);
                    if(newdiff < dist[nr][nc]){
                        dist[nr][nc] = newdiff;
                        pq.push({newdiff, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};