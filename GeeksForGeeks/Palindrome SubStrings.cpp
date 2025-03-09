//link
//https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1

class Solution {
    public:
      int countPS(string &s) {
          // code here
          int ans = 0;
          for(int i = 0; i < s.length(); i++){
              int l = i, r = i;
              
              while(l >= 0 && r < s.length() && s[l] == s[r]){
                  ans++;
                  l--;
                  r++;
              }
              
              l =  i, r = i + 1; 
              while(l >= 0 && r < s.length() && s[l] == s[r]){
                  ans++;
                  l--;
                  r++;
              }
          }
          
          return ans - s.length();
      }
  };