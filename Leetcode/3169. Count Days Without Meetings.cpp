//link
//https://leetcode.com/problems/count-days-without-meetings/

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            if (meetings.empty()) {
                return days;
            }
            
            sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int>& b){
                return a[0] < b[0];
            });
    
            vector<vector<int>> merged;
            merged.push_back(meetings[0]);
    
            for(int i = 1; i < meetings.size(); i++){
                if(merged.back()[1] >= meetings[i][0]){
                    merged.back()[1] = max(merged.back()[1], meetings[i][1]);
                }
                else{
                    merged.push_back(meetings[i]);
                }
            }
    
            int ans = 0;
            ans += merged[0][0] - 1;
    
            for(int i = 0; i < merged.size() - 1; i++){
                ans += merged[i + 1][0] - merged[i][1] - 1;
            }
    
            ans += days - merged.back()[1];
    
            return ans;
        }
    };