//link
//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            mat[u][v] = w;
            mat[v][u] = w;
        }

        for(int i = 0; i < n; i++){
            mat[i][i] = 0;
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        vector<int> result(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                if(mat[i][j] <= distanceThreshold){
                    result[i]++;
                    result[j]++;
                }
            }
        }
        int max = INT_MAX;
        int city = -1;
        for(int i = 0; i < n; i++){
            if(result[i] <= max){
                max = result[i];
                city = i;
            }
        }

        return city;
    }
};