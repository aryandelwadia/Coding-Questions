//link
//https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(char& ch : s){
            m[ch]++;
        }

        vector<pair<char, int>> alpha(m.begin(), m.end());
        sort(alpha.begin(), alpha.end(), [](pair<char, int>& a, pair<char, int>& b) {
            if (a.second > b.second) return true;
            if (a.second < b.second) return false;
            return a.first > b.first;
        });

        string ans = "";
        for(auto& it : alpha){
            char ch = it.first;
            int n = it.second;
            for(int i = 0; i < n; i++){
                ans.push_back(ch);
            }
        }

        return ans;
    }
};