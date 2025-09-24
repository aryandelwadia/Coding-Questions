//link
//https://leetcode.com/problems/fraction-to-recurring-decimal/description/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // return "";
        if(numerator == 0) return "0";
        string ans = "";

        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)){
            ans.push_back('-');
        }

        long long nume = llabs((long long) numerator);
        long long deno = llabs((long long) denominator);
        ans += (to_string(nume / deno));

        long long r = nume % deno;
        if(r == 0) return ans;

        ans.push_back('.');
        unordered_map<long long, int> m;
        while(r != 0){
            if(m.count(r)){
                ans.insert(m[r], "(");
                ans += ")";
                break;
            }
            m[r] = ans.size();
            r *= 10;
            ans += to_string(r / deno);
            r %= deno;
        }

        return ans;
    }
};