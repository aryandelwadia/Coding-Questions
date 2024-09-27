//linik
//https://leetcode.com/problems/last-stone-weight/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i: stones){
            pq.push(i);
        }

        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            if(a != b){
                pq.push(abs(a - b));
            }
        }

        if (pq.size() == 0){
            return 0;
        }
        else{
            return pq.top();
        }
    }
};