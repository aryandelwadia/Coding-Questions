//link
//https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string s) {
        string ans = "";
        int i = 0;
        int n = s.length();

        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i == n) return 0;

        bool negative = false;
        if (s[i] == '-') {
            negative = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        int result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            if (result > (INT_MAX - digit) / 10) {
                return negative ? INT_MIN : INT_MAX;
            }
            
            result = result * 10 + digit;
            i++;
        }

        return negative ? -result : result;
    }
};