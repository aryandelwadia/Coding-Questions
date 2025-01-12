//link
//https://www.geeksforgeeks.org/problems/number-of-provinces/1

class Solution {
  private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited){
        visited[node] = 1;
        for(int i = 0; i < adj.size(); i++){
            if(i != node && adj[node][i] == 1){
                if(!visited[i]){
                    dfs(i, adj, visited);
                }
            }
        }
    }
  
    int solve(vector<vector<int>> &adj, vector<int> &visited){
        int ans = 0;
        for(int i = 0; i < adj.size(); i++){
            if(!visited[i]){
                ans++;
                dfs(i, adj, visited);
            }
        }
        
        return ans;
    }

  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> visited(V, 0);
        return solve(adj, visited);
    }
};