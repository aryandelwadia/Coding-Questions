//link
//https://www.geeksforgeeks.org/problems/maximize-partitions-in-a-string/1

class Solution {
    public:
      int maxPartitions(string &s) {
          // code here
          unordered_map<char, int> last;
          
          for(int i = 0; i < s.length(); i++){
              last[s[i]] = i;
          }
          
          int ans = 0;
          int l = 0, r = 0;
          
          for(int i = 0; i < s.length(); i++){
              r = max(r, last[s[i]]);
              
              if(i == r){
                  l = i + 1;
                  ans++;
              }
          }
          
          return ans;
      }
  };