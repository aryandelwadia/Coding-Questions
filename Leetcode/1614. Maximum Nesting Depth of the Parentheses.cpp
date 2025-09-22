//link
//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;
        int curr = 0;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == '('){
                curr++;
                st.push(ch);
                ans = max(ans, curr);
            }
            else if(ch == ')'){
                st.pop();
                curr--;
            }
        }

        return ans;
    }
};