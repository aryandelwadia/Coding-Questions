//link
//https://leetcode.com/problems/course-schedule?envType=problem-list-v2&envId=graph

class Solution {
private:
    bool checkCycle(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto i : adj[node]){
            if(!visited[i]){
                bool cycle = checkCycle(i, adj, visited, dfsVisited);
                if(cycle){
                    return true;
                }
            }
            else if(dfsVisited[i]){
                return true;
            }
        }   

        dfsVisited[node] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;

        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        unordered_map<int, bool> visited(numCourses);
        unordered_map<int, bool> dfsVisited(numCourses);

        for(int i = 0; i < numCourses; i++){
            bool cycle = checkCycle(i, adj, visited, dfsVisited);
            if(cycle){
                return false;
            }
        }

        return true;
    }
};