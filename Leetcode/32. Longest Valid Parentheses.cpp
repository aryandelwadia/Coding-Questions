//Link
//https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n == 0){
            return 0;
        }

        stack<int> st;
        st.push(-1);
        int longestvalid = 0;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    longestvalid = max(longestvalid, i - st.top());
                }
            }
        }

        return longestvalid;
    }
};