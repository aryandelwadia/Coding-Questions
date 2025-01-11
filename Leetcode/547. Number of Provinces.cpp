//link
//https://leetcode.com/problems/number-of-provinces

class Solution {
private:
    void dfs(int node, vector<int> &visited, vector<vector<int>>& isConnected){
        visited[node] = true;

        for(int i = 0; i < isConnected.size(); i++){
            if(i != node && isConnected[node][i] == 1){
                if(!visited[i]){
                    dfs(i, visited, isConnected);
                }
            }
        }
    }

    int solve(vector<int> &visited, vector<vector<int>>& isConnected){
        int ans = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                ans++;
                dfs(i, visited, isConnected);
            }
        }
        return ans;
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size());
        return solve(visited, isConnected); 
    }
};