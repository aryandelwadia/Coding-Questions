//link
//https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> numbers;

        for(int i = 0; i < nums.size(); i++){
            numbers[nums[i]]++;
        }

        int i = 1;
        while(true){
            if(numbers.count(i)){
                i++;
            }
            else{
                break;
            }
        }

        return i;
    }
};