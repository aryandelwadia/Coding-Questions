//link
//https://leetcode.com/problems/largest-3-same-digit-number-in-string/

class Solution {
public:
    string largestGoodInteger(string num) {
        string maxGood = "";

        for (int i = 0; i <= num.size() - 3; ++i) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string good = num.substr(i, 3);
                if (good > maxGood) {
                    maxGood = good;
                }
            }
        }

        return maxGood;
    }
};
