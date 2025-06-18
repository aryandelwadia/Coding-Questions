//link
//https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

class Solution {
  public:
    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        
        return true;
    }
  
    void solve(int index, string &s, vector<vector<string>>& ans, vector<string>& curr){
        if(index == s.length()){
            ans.push_back(curr);
            return;
        }
        
        for(int i = index; i < s.length(); i++){
            if(isPalindrome(s, index, i)){
                curr.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, ans, curr);
                curr.pop_back();
            }
        }
    }
  
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0, s, ans, curr);
        return ans;
    }
};