//link
//https://leetcode.com/problems/fruit-into-baskets/description

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int l = 0, r = 0;
        int n = fruits.size();
        int ans = 0;

        while(r < n){
            int num = fruits[r];
            m[num]++;
            if(m.size() > 2){
                while(m.size() != 2){
                    m[fruits[l]]--;
                    if(m[fruits[l]] == 0){
                        m.erase(fruits[l]);
                    }
                    l++;
                }
            }

            int temp = 0;
            for(auto& it : m){
                temp += it.second;
            }
            ans = max(ans, temp);
            r++;
        }

        return ans;
    }
};