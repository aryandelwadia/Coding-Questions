//link
//https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        vector<int> ans;
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);
            for(auto i : adj[node]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
    
        if(ans.size() != numCourses){
            vector<int> e;
            return e;
        }
        else{
            return ans;
        }
    }
};