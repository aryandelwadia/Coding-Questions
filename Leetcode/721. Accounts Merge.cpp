//link
//https://leetcode.com/problems/accounts-merge

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
        if(parent[x] == x){
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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mails;
        DisjointSet ds(n);
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mails.find(mail) == mails.end()){
                    mails[mail] = i;
                }
                else{
                    ds.unionBySize(i, mails[mail]);
                }
            }
        }

        vector<string> merge[n];
        for(auto i : mails){
            string mail = i.first;
            int node = ds.find(i.second);
            merge[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(merge[i].size() != 0){
                vector<string> temp;
                sort(merge[i].begin(), merge[i].end());
                temp.push_back(accounts[i][0]);
                for(auto i : merge[i]){
                    temp.push_back(i);
                }
                ans.push_back(temp);
            }
        }

        return ans;
    }
};