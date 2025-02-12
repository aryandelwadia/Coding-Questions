//link
//https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits

class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            vector<int> sum(nums.size(), 0);
            vector<pair<int, int>> sums;
    
            for(int i = 0; i < nums.size(); i++){
                int n = nums[i];
                int sum = 0;
                while(n > 0){
                    sum += n % 10;
                    n = n / 10;
                }
                sums.push_back({sum, nums[i]});
            }
    
            sort(sums.begin(), sums.end());
    
            int maxSum = -1;
    
            for(int i = 1; i < sums.size(); i++){
                int curr = sums[i].first;
                int prev = sums[i - 1].first;
    
                if(curr == prev){
                    int currSum = sums[i].second + sums[i - 1].second;
                    maxSum = max(maxSum, currSum);
                }
            }
    
            return maxSum;
        }
    };