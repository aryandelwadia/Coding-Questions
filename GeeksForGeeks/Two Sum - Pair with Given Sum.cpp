//link
//https://www.geeksforgeeks.org/problems/key-pair5616/1

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_set<int> s;
        for (int i = 0; i < arr.size(); i++){
            int complement = target - arr[i];
            if (s.find(complement) != s.end())
                return true;
            s.insert(arr[i]);
        }
        return false;
    }
};