//link
//https://leetcode.com/problems/making-a-large-island

class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unionBySize(int u, int v){
        int uu = find(u);
        int uv = find(v);

        if(uu == uv){
            return;
        }

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
private:
    bool isValid(int u, int v, int n){
        return u >= 0 && u < n && v >= 0 && v < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0){
                    continue;
                }

                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, 1, 0, -1};

                for(int i = 0; i < 4; i++){
                    int nr = row + drow[i];
                    int nc = col + dcol[i];
                    if(isValid(nr, nc, n) && grid[nr][nc] == 1){
                        int nodeNo = row * n + col;
                        int adjNo = nr * n + nc;
                        ds.unionBySize(nodeNo, adjNo);
                    }
                }
            }
        }

        int mx = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1){
                    continue;
                }

                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, 1, 0, -1};
                set<int> s;

                for(int i = 0; i < 4; i++){
                    int nr = row + drow[i];
                    int nc = col + dcol[i];
                    if(isValid(nr, nc, n) && grid[nr][nc] == 1){
                        s.insert(ds.find(nr * n + nc));
                    }
                }

                int total = 0;
                for(auto i : s){
                    total += ds.size[i];
                }
                mx = max(mx, total + 1);
            }
        }

        for(int i = 0; i < n * n; i++){
            mx = max(mx, ds.size[ds.find(i)]);
        }
        return mx;
    }
};