//link
//https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s)
    {

        vector<int> freq(26);
        int n = s.length();

        for(int i = 0; i < n; i++)
        {
            freq[s[i] - 'a'] += 1;
        }
        int ans = -1;

        for(int i = 0; i < n; i++)
        {
            if(freq[s[i] - 'a'] == 1)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};