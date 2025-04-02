//link
//https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long ans = INT_MIN;
            for(int i = 0; i < nums.size(); i++){
                for(int j = i + 1; j < nums.size(); j++){
                    for(int k = j + 1; k < nums.size(); k++){
                        long long a = nums[i];
                        long long b = nums[j];
                        long long c = nums[k];
                        long long result = (a - b) * c;
                        ans = max(ans, result);
                    }
                }
            }
    
            return ans > 0 ? ans : 0;
        }
    };