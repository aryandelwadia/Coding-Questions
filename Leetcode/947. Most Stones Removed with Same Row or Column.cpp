//link
//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);

        for(int i = 0; i <= n; i++){
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

    void unionSize(int u, int v){
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
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        int n = 0;
        for(auto i : stones){
            int u = i[0];
            int v = i[1];
            n++;

            maxRow = max(maxRow, u);
            maxCol = max(maxCol, v);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNode;

        for(auto i : stones){
            int u = i[0];
            int v = i[1] + maxRow + 1;

            ds.unionSize(u, v);
            stoneNode[u] = 1;
            stoneNode[v] = 1;
        }

        int count = 0;

        for(auto i : stoneNode){
            if(ds.find(i.first) == i.first){
                count++;
            }
        }

        return n - count;
    }
};