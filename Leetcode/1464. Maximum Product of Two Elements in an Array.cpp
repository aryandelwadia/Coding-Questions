//link
//https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;

        for(auto i : nums){
            pq.push(i);
        }

        int n = pq.top();
        pq.pop();

        return (n - 1) * (pq.top() - 1);
    }
};