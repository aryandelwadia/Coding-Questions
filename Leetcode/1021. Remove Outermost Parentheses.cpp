//link
//https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int count = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                if(count > 0){
                    result.push_back(s[i]);
                }
                count++;
            }
            else{
                count--;
                if(count > 0){
                    result.push_back(s[i]);
                }
            }
        }

        return result;
    }
};