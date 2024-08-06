//Link
//https://www.naukri.com/code360/problems/redundant-brackets_975473

#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    bool ans = false;

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '*' || ch == '/' || ch == '-'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                ans = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '*' || top == '/' || top == '-'){
                        ans = false;
                    }
                    st.pop();
                }

                if(ans){
                    return ans;
                }
                st.pop();
            }
        }
    }

    return false;
}
