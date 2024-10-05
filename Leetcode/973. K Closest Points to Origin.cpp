//link
//https://leetcode.com/problems/k-closest-points-to-origin/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;

        for(int i = 0; i < points.size(); i++){
            int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({d, points[i]});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            pair<int, vector<int>> top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }

        return ans;
    }
};