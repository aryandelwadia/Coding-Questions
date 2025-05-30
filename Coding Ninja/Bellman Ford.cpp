//link
//https://www.naukri.com/code360/problems/bellmon-ford_2041977

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.

    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u] != 1e9 && (dist[u] + w < dist[v])){
                dist[v] = dist[u] + w;
            }
        }
    }

    return dist;
}