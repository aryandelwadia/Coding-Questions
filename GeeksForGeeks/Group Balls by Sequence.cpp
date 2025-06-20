//link
//https://www.geeksforgeeks.org/problems/group-balls-by-sequence/1

class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if(n % k != 0) return false;

        map<int, int> freq;
        for(int num : arr) {
            freq[num]++;
        }

        while(!freq.empty()) {
            int start = freq.begin()->first;
            for(int i = 0; i < k; i++) {
                if(freq[start + i] == 0) {
                    return false;
                }
                freq[start + i]--;
                if(freq[start + i] == 0) {
                    freq.erase(start + i);
                }
            }
        }
        return true;
    }
};
