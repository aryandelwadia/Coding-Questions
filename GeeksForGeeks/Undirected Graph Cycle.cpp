//link
//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

vector<bool> visited(adj.size(), false);
        
        for(int i = 0; i < adj.size(); i++){
            if(!visited[i]){
                bool cycle = bfs(i, adj, visited);
                if(cycle){
                    return true;
                }
            }
        }
        
        return false;