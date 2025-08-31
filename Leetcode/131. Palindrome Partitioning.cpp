//link
//https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(string s, vector<vector<string>>& ans, vector<string> curr, int ind){
        if(ind == s.length()){
            ans.push_back(curr);
            return;
        }

        for(int i = ind; i < s.length(); i++){
            if(isPalindrome(s, ind, i)){
                curr.push_back(s.substr(ind, i - ind + 1));
                solve(s, ans, curr, i + 1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(s, ans, curr, 0);
        return ans;
    }
};