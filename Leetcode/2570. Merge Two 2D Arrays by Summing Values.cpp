//link
//https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values?envType=daily-question&envId=2025-03-02

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            unordered_map<int, int> nums;
            for(auto& i : nums1){
                int n = i[0];
                int m = i[1];
                nums[n] += m;
            }
            for(auto& i : nums2){
                int n = i[0];
                int m = i[1];
                nums[n] += m;
            }
    
            vector<vector<int>> ans;
            for(auto& i : nums){
                int n = i.first;
                int m = i.second;
                vector<int> temp;
                temp.push_back(n);
                temp.push_back(m);
                ans.push_back(temp);
            }
            sort(ans.begin(), ans.end())
            return ans;
        }
    };