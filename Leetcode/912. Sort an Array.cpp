//link
//https://leetcode.com/problems/sort-an-array/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};