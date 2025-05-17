//link
//https://www.geeksforgeeks.org/problems/sort-the-given-array-after-applying-the-given-equation0304/1

class Solution {
  public:
    int solve(int n, int A, int B, int C){
        int ans = (A * n * n) + (B * n) + C;
        return ans;
    }
  
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++){
            int result = solve(arr[i], A, B, C);
            ans.push_back(result);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};