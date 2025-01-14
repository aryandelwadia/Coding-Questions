//link
//https://leetcode.com/problems/find-eventual-safe-states

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector < vector < int >> rev(graph.size());
        vector<int> indegree(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            for (auto j : graph[i]) {
                rev[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < graph.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for(auto i : rev[front]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};