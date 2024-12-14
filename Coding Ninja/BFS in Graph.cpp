//link
//https://www.naukri.com/code360/problems/bfs-in-graph_973002

void bfs(vector<vector<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited, int node){
    
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(int j = 0; j < adj[frontNode].size(); j++){
            if(!visited[adj[frontNode][j]]){
                q.push(adj[frontNode][j]);
                visited[adj[frontNode][j]] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int> ans;
    unordered_map<int, bool> visited;

    bfs(adj, ans, visited, 0);

    return ans;
}