//link
//https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
    public:
        int characterReplacement(string s, int k) {
            vector<int> arr(26, 0);
            int l = 0;
            int r = 0;
            int maxLen = 0, maxFreq = 0;
    
            while(r < s.length()){
                arr[s[r] - 'A']++;
                maxFreq = max(maxFreq, arr[s[r] - 'A']);
    
                while((r - l + 1) - maxFreq > k){
                    arr[s[l] - 'A']--;
                    l++;
                    for(int i = 0; i < 26; i++) maxFreq = max(maxFreq, arr[i]);
                }
    
                if((r - l + 1) - maxFreq <= k){
                    maxLen = max(maxLen, r - l + 1);
                }
                r++;
            }
    
            return maxLen;
        }
    };