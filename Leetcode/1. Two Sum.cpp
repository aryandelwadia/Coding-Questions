//link
//https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numbers;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            numbers[nums[i]] = i;
        }

        for(int i = 0; i < n; i++){
            int compliment = target - nums[i];
            if(numbers.count(compliment) && numbers[compliment] != i){
                return {i, numbers[compliment]};
            }
        }

        return {};
    }
};