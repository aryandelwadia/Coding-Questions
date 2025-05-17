//link
//https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int l = 0, r = 0, sIndex = -1, minLen = 100000000, count = 0;
        vector<int> hash(256, 0);
        for(int i = 0; i < t.length(); i++){
            hash[t[i]]++;
        }

        while(r < n){
            if(hash[s[r]] > 0){
                count++;
            }
            hash[s[r]]--;
            while(count == t.size()){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    count--;
                }
                l++;
            }

            r++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};