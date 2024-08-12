//link
//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == '('){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    st.push(ch);
                }
                else{
                    char top = st.top();
                    if(top == '('){
                        st.pop();
                    }
                    else{
                        st.push(ch);
                    }
                }
            }
        }
        return st.size();
    }
};