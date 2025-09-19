//link
//https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> s;
        for(int i = 0; i < brokenLetters.length(); i++){
            s.insert(brokenLetters[i]);
        }

        int ans = 0;
        bool flag = false;

        for(int i = 0; i < text.length(); i++){
            char ch = text[i];
            if(ch == ' '){
                if(!flag) ans++;
                flag = false;
                continue;
            }
            else{
                if(!flag && s.count(ch)){
                    flag = true;
                }
            }
        }
        if(!flag) ans++;
        return ans;
    }
};