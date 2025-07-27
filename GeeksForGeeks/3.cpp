//link
//https://www.geeksforgeeks.org/problems/majority-vote/1

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        unordered_map<int, int> m;
        int n = arr.size();
        int mini = n / 3;
        
        for(int i = 0; i < n; i++) {
            m[arr[i]]++;
        }
        
        vector<int> ans;
        for(auto i : m) {
            if(i.second > mini) {
                ans.push_back(i.first);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
