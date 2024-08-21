//link
//https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633

#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(const string& s) {
    string str;
    
    for (char c : s) {
        if (isalnum(c)) {
            str.push_back(tolower(c));
        }
    }

    int st = 0;
    int e = str.length() - 1;
    
    while (st <= e) {
        if (str[st] != str[e]) {
            return false;
        }
        st++;
        e--;
    }
    
    return true;
}
