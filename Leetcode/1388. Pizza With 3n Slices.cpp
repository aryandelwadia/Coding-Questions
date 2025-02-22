//link
//https://leetcode.com/problems/pizza-with-3n-slices

class Solution {
    private:
        int solveTab(vector<int>& slices){
            int k = slices.size();
    
            vector<int> prev1(k + 2, 0);
            vector<int> next1(k + 2, 0);
            vector<int> curr1(k + 2, 0);
    
            vector<int> prev2(k + 2, 0);
            vector<int> next2(k + 2, 0);
            vector<int> curr2(k + 2, 0);
    
            for(int index = k - 2; index >= 0; index--){
                for(int n = 1; n <= k/3; n++){
                    int include = 0;
                    include = slices[index] + next1[n - 1];
                    int exclude = curr1[n];
                    prev1[n] = max(include, exclude);
                }
    
                next1 = curr1;
                curr1 = prev1;
            }
    
            for(int index = k - 1; index >= 1; index--){
                for(int n = 1; n <= k/3; n++){
                    int include = 0;
                    include = slices[index] + next2[n - 1];
                    int exclude = curr2[n];
                    prev2[n] = max(include, exclude);
                }
                next2 = curr2;
                curr2 = prev2;
            }
    
            return max(curr1[k / 3], curr2[k / 3]);
        }
    
    public:
        int maxSizeSlices(vector<int>& slices) {
            return solveTab(slices);
        }
    };