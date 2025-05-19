//link
//https://leetcode.com/problems/largest-odd-number-in-string/description/

class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;
        for(int i = num.size() - 1; i >= 0; i--){
            int n = num[i] - '0';
            if(n % 2 == 1){
                index = i;
                break;
            }
        }

        return index == -1 ? "" : num.substr(0, index + 1);
    }
};