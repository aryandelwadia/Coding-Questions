//link
//https://leetcode.com/problems/max-chunks-to-make-sorted?envType=daily-question&envId=2024-12-19
#include<bits/stdc++.h>

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        vector<int> leftMax(n);
        vector<int> rightMin(n);

        leftMax[0] = arr[0];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        }

        rightMin[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            rightMin[i] = min(rightMin[i + 1], arr[i]);
        }

        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            if(leftMax[i] <= rightMin[i + 1]){
                ans++;
            }
        }

        return ans + 1;
    }
};