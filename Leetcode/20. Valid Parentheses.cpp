//link
//https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0){
            return true;
        }

        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char top = st.top();
                    if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }

        return st.empty()? true : false;
    }
};