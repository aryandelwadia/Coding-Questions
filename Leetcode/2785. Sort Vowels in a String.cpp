//link
//https://leetcode.com/problems/sort-vowels-in-a-string/description/

class Solution {
public:
    string sortVowels(string s) {
        vector<char> alpha;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' ||
                ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U'){  
                    alpha.push_back(ch);
                }
        }
        int j = 0;
        sort(alpha.begin(), alpha.end());
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' ||
                ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U'){
                    s[i] = alpha[j];
                    j++;
                }
        }

        return s;
    }
};