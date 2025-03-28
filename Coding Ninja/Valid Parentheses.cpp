//Link
//https://www.naukri.com/code360/problems/valid-parenthesis_795104

#include<bits/stdc++.h>

bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            if (!st.empty()) {
              char top = st.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
                  (ch == ']' && top == '[')){
                      st.pop();
                }
                else{
                    return false;
                }

            } else {
              return false;
            }
        }
    }

    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}