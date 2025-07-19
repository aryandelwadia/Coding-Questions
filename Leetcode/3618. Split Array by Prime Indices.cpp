//link
//https://leetcode.com/problems/split-array-by-prime-indices/description/

class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    long long splitArray(vector<int>& nums) {
        long long sumA = 0, sumB = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (isPrime(i)) {
                sumA += nums[i];
            } else {
                sumB += nums[i];
            }
        }

        return abs(sumA - sumB);
    }
};
