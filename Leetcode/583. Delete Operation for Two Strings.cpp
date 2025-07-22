//link
//https://leetcode.com/problems/delete-operation-for-two-strings/description/

class Solution {
public:
    int solve(string& s, string& t){
        int m = s.length();
        int n = t.length();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        
        for(int i = 1; i <= m; i++){
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

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int common = solve(word1, word2);

        return (m - common) + (n - common);
    }
};