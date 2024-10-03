//link
//https://leetcode.com/problems/relative-ranks/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue< pair<int, int> > pq;

        for(int i = 0; i < score.size(); i++){
            pq.push({score[i], i});
        }

        vector<string> ans(score.size());
        int place = 1;
        while(!pq.empty()){
            int index = pq.top().second;
            pq.pop();
            if(place == 1){
                ans[index] = "Gold Medal";
            }
            else if(place == 2){
                ans[index] = "Silver Medal";
            }
            else if(place == 3){
                ans[index] = "Bronze Medal";
            }
            else{
                ans[index] = to_string(place);
            }
            place++;
        }

        return ans;
    }
};