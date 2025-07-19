//link
//https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/description/

class DisjointSet{
public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int n){
        size.resize(n , 0);
        parent.resize(n , 0);

        for(int i = 0; i < n; i++){
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findParent(int n){
        if(parent[n] == n){
            return n;
        }
        return parent[n] = findParent(parent[n]);
    }

    void unionSize(int u, int v){
        int uu = findParent(u);
        int uv = findParent(v);
        if(uu == uv) return;
        if(size[uu] < size[uv]){
            parent[uu] = uv;
            size[uv] += size[uu];
        }
        else{
            parent[uv] = uu;
            size[uu] += size[uv];
        }
    }
};

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int dx[] = {- 1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        DisjointSet ds(m * n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j] == 0) continue;
                
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 0){
                        int u = i * n + j;
                        int v = nx * n + ny;

                        ds.unionSize(u, v);
                    }
                }
            }
        }

        unordered_map<int, long long> islandValue;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int node = i * n + j;
                int root = ds.findParent(node);
                islandValue[root] += grid[i][j];
            }
        }

        int count = 0;
        for (auto& [root, sum] : islandValue) {
            if (sum % (long long)k == 0) {
                count++;
            }
        }

        return count;
    }
};