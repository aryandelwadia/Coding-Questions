//link
//https://leetcode.com/problems/jump-game-iii/description/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            if (front < 0 || front >= n || visited[front]) continue;
            
            visited[front] = true;
            if(arr[front] == 0){
                return true;
            }
            
            q.push(front + arr[front]);
            q.push(front - arr[front]);
        }

        return false;
    }
};