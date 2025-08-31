//link
//https://leetcode.com/problems/jump-game-iv/description/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> m;
        int n = arr.size();

        for(int i = 0; i < n; i++){
            m[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        int ans = 0;

        while(!q.empty()){
            int size = q.size();

            for(int itr = 0; itr < size; itr++){
                int front = q.front();
                q.pop();

                if(front == n - 1) return ans;

                if(front - 1 >= 0 && !visited[front - 1]) {
                    q.push(front - 1);
                    visited[front - 1] = true;
                }

                if(front + 1 < n && !visited[front + 1]) {
                    q.push(front + 1);
                    visited[front + 1] = true;
                }

                for(int i = 0; i < m[arr[front]].size(); i++){
                    int ele = m[arr[front]][i];
                    if(!visited[ele]) {
                        q.push(ele);
                        visited[ele] = true;
                    }
                }

                m[arr[front]].clear();
            }

            ans++;
        }

        return ans;
    }
};
