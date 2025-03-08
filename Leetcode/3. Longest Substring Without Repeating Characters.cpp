//linkn
//https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int l = 0, r = 0, ans = 0;
            unordered_map<char, int> chars;
    
            while(r < s.length()){
                if(chars.count(s[r])){
                    if(chars[s[r]] >= l){
                        l = chars[s[r]] + 1;
                    }
                }
                int len = r - l + 1;
                ans = max(ans, len);
                chars[s[r]] = r;
                r++;
            }
    
            return ans;
        }
    };