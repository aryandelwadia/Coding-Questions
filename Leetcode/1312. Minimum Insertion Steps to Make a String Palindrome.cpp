//link
//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

class Solution {
public:
    int solve(string& s, string& t){
        int n = s.length();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == t[j - 1]){
                    curr[j] = 1 + prev[j - 1];
                }
                else{
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[n];
    }

    int minInsertions(string s) {
        int n = s.length();
        string rev = s;
        reverse(s.begin(), s.end());
        return n - solve(s, rev);
    }
};