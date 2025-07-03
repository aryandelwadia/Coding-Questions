//link
//https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int ans = -1;
        int n = s.length();
        int l = 0, r = 0;
        unordered_map<char, int> m;
        
        while(r < n){
            m[s[r]]++;
            if(m.size() > k){
                while(m.size() > k){
                    char ch = s[l];
                    l++;
                    m[ch]--;
                    if(m[ch] == 0){
                        m.erase(ch);
                    }
                }
            }
            
            if(m.size() == k){
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        
        return ans;
    }
};