//Link
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:

    void solve(string digits, vector<string>& ans, string map[], string str, int i){
        if(i >= digits.length()){
            ans.push_back(str);
            return;
        }

        // char ch = digits[i];
        // int num = stoi(ch);

        int num = digits[i] - '0';
        string letter = map[num];

        for(int j = 0; j < letter.length(); j++){
            str.push_back(letter[j]);
            solve(digits, ans, map, str, i + 1);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0){
            return ans;
        }

        string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string str;
        int i = 0;
        
        solve(digits, ans, map, str, i);
        return ans;
    }
};