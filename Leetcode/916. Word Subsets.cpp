//link
//https://leetcode.com/problems/word-subsets?envType=daily-question&envId=2025-01-10

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int maxi[26] = {0};

        for(auto word : words2){
            int temp[26] = {0};
            for(char ch : word){
                temp[ch - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                maxi[i] = max(maxi[i], temp[i]);
            }
        }

        vector<string> ans;
        for(auto word : words1){
            int temp[26] = {0};
            for(auto ch : word){
                temp[ch - 'a']++;
            }
            bool flag = true;
            for(int i = 0; i < 26; i++){
                if(maxi[i] > temp[i]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans.push_back(word);
            }
        }
        return ans;
    }
};