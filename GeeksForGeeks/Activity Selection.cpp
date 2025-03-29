//link
//https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

struct Activity{
    int start;
    int finish;
};

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<Activity> act(n);
        
        for(int i = 0; i < n; i++){
            act[i].start = start[i];
            act[i].finish = finish[i];
        }
        
        sort(act.begin(), act.end(), [](Activity a, Activity b){
            return a.finish < b.finish;   
        });
        
        int last = -1;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(act[i].start > last){
                ans++;
                last = act[i].finish;
            }
        }
        
        return ans;
    }
};