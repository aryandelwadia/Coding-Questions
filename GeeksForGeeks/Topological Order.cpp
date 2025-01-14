//link
//https://www.geeksforgeeks.org/problems/topological-sort/1

#include<bits/stdc++.h>
class Solution {
  private:
    void dfs(int node, vector<bool> &visited, vector<vector<int>>& adj, stack<int> &st){
        visited[node] = true;
        for(auto i : adj[node]){
            if(!visited[i]){
                dfs(i, visited, adj, st);
            }
        }
        st.push(node);
    }
    
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        vector<bool> visited(adj.size(), false);
        stack<int> st;
        vector<int> ans;
        for(int i = 0; i < adj.size(); i++){
            if(!visited[i]){
                dfs(i, visited, adj, st);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};