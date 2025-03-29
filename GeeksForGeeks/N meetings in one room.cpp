//link
//https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution {
    public:
      // Function to find the maximum number of meetings that can
      // be performed in a meeting room.
      int maxMeetings(vector<int>& start, vector<int>& end) {
          // Your code here
          int n = start.size();
          vector<pair<int, int> > meet;
          for(int i = 0; i < n; i++){
              meet.push_back({start[i], end[i]});
          }
          
          sort(meet.begin(), meet.end(), [](pair<int, int>& a, pair<int, int>& b){
              return a.second < b.second;
          });
          
          int ans = 0;
          int last = -1;
          for(int i = 0; i < n; i++){
              if(meet[i].first > last){
                  ans++;
                  last = meet[i].second;
              }
          }
          
          return ans;
      }
  };