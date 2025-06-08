//link
//https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1

class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n = a1.size();
        vector<int> diff(n);

        for (int i = 0; i < n; i++) {
            diff[i] = a1[i] - a2[i];
        }

        unordered_map<int, int> prefixSumIndex;
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            sum += diff[i];

            if (sum == 0) {
                maxLen = i + 1;
            } else if (prefixSumIndex.find(sum) != prefixSumIndex.end()) {
                maxLen = max(maxLen, i - prefixSumIndex[sum]);
            } else {
                prefixSumIndex[sum] = i;
            }
        }

        return maxLen;
    }
};