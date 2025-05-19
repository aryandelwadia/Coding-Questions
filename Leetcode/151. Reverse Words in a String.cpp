//link
//https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> words;
        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') i++;

            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            if (!word.empty()) {
                words.push_back(word);
            }
        }

        reverse(words.begin(), words.end());

        string result = "";
        for (int j = 0; j < words.size(); ++j) {
            result += words[j];
            if (j != words.size() - 1)
                result += " ";
        }

        return result; 
    }
};