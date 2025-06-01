//link
//https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1

class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n = mat1.size();
        int i = 0;
        int j = (n * n) - 1;
        
        int count = 0;
        while(i <= (n * n) - 1 && j >= 0){
            int sum = mat1[i / n][i % n] + mat2[j / n][j % n];
            if(sum == x){
                count++;
                i++;
                j--;
            }
            else if(sum > x){
                j--;
            }
            else{
                i++;
            }
        }
        
        return count;
    }
};