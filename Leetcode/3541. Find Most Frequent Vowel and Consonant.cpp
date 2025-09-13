//link
//https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); i++){
            m[s[i]]++;
        }

        int v = 0;
        int c = 0;

        for(auto& it : m){
            if(it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u'){
                v = max(v, it.second);
            }
            else{
                c = max(c, it.second);
            }
        }

        return v + c;
    }
};