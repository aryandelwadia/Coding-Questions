//link
//https://leetcode.com/problems/russian-doll-envelopes

class Solution {
    private:
        int solve(vector<int> &arr){
            // int n = arr.size();
            // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
            // vector<int> currRow(n + 1, 0);
            // vector<int> nextRow(n + 1, 0);
    
            // for(int curr = n - 1; curr >= 0; curr--){
            //     for(int prev = curr - 1; prev >= -1; prev--){
            //         int include = 0;
            //         if(prev == -1 || arr[curr] > arr[prev]){
            //             include = 1 + nextRow[curr + 1];
            //         }
            //         int exclude = nextRow[prev + 1];
            //         currRow[prev + 1] = max(include, exclude);
            //     }
            //     nextRow = currRow;
            // }
            // return nextRow[0];
    
            int n = arr.size();
            if(n == 0){
                return 0;
            }
    
            vector<int> ans;
            ans.push_back(arr[0]);
            for(int i = 1; i < n; i++){
                if(arr[i] > ans.back()){
                    ans.push_back(arr[i]);
                }
                else{
                    int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                    ans[index] = arr[i];
                }
            }
            return ans.size();
        }
        static bool cmp(vector<int> &a, vector<int> &b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        }
    
    public:
        int maxEnvelopes(vector<vector<int>>& envelopes) {
            int m = envelopes.size();
            int n = envelopes[0].size();
    
            sort(envelopes.begin(), envelopes.end(), cmp);
    
            vector<int> arr;
            for(int i = 0; i < m; i++){
                arr.push_back(envelopes[i][1]);
            }
    
            return solve(arr);
        }
    };