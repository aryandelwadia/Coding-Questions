//link
//https://leetcode.com/problems/reach-a-number/description/

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int i = 1;
        while(sum < target){
            sum += i;
            i++;
        }

        while((sum - target) % 2 == 1){
            sum += i;
            i++;
        }
        return i - 1;
    }
};