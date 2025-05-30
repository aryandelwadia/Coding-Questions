//link
//https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    
            for(auto i : nums){
                pq.push(i);
            }
            int count = 0;
            while(pq.top() < k){
                long long int a = pq.top();
                pq.pop();
                long long int b = pq.top();
                pq.pop();
                long long sum = min(a, b) * 2 + max(a, b);
                pq.push(sum);
                count++;
            }
    
            return count;
        }
    };