//link
//https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        int target = 0;
        sort(nums.begin(), nums.end());

        if(nums.back()<=0 && nums.front()>=0) return {{0,0,0}};
        if(nums.back()<0&&nums.front()<0) return {};
        if(nums.back()>0&&nums.front()>0) return {};

        for(int i = 0; i < nums.size() - 2; i++){
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target){
                    s.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(sum < target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }

        vector<vector<int>> ans(s.begin(), s.end());

        return ans;
    }
};