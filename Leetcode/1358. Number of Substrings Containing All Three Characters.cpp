//link
//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters?envType=daily-question&envId=2025-03-11

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int ans = 0;
            int last[3] = {-1, -1, -1};
    
            for(int i = 0; i < s.length(); i++){
                last[s[i] - 'a'] = i;
                if(last[0] != -1 && last[1] != -1 && last[2] != -1){
                    ans += 1 + min(last[0], min(last[1], last[2]));
                }
            }
    
            return ans;
        }
    };