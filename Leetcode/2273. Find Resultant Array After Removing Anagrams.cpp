//link
//https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/

class Solution {
public:
    bool isAnagram(string& s1, string &s2){
        if(s1.length() != s2.length()){
            return false;
        }

        int freq[26] = {0};
    
        for (char c : s1) {
            freq[c - 'a']++;
        }
        
        for (char c : s2) {
            freq[c - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) return false;
        }

        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        if (words.empty()) {
            return words;
        }

        vector<string> result;
        result.push_back(words[0]);

        for (int i = 1; i < words.size(); ++i) {
            if (!isAnagram(result.back(), words[i])) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};