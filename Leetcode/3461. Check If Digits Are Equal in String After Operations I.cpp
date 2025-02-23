//link
//https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i

class Solution {
    public:
        bool hasSameDigits(string s) {
            while(s.size() > 2){
                string str = "";
                for(int i = 0; i < s.size() - 1; i++){
                    int n1 = s[i] - '0';
                    int n2 = s[i + 1] - '0';
                    int num = (n1 + n2) % 10;
                    str.push_back(num + '0');
                }
                s = str;
            }
    
            return s[0] == s[1];
        }
    };