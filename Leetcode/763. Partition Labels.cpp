//link
//https://leetcode.com/problems/partition-labels/

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<char, int> last;
            for (int i = 0; i < s.length(); ++i) {
                last[s[i]] = i;
            }
    
            vector<int> ans;
            int l = 0, r = 0;
            for(int i = 0; i < s.length(); i++){
                r = max(r, last[s[i]]);
    
                if(i == r){
                    ans.push_back(i - l + 1);
                    l = i + 1;
                }
            }
    
            return ans;
        }
    };