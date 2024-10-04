//link
//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> ans;

        for(int i = 0; i < nums1.size(); i++){
            pq.push({nums1[i] + nums2[0], 0});
        }

        while(k-- && !pq.empty()){
            pair<int, int> top = pq.top();
            pq.pop();

            int sum = top.first;
            int pos = top.second;
            ans.push_back({sum - nums2[pos], nums2[pos]});

            if(pos + 1 < nums2.size()){
                pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
            }
        }

        return ans;
    }
};