//link
//https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int totalSum = 0;
        int leftSum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            totalSum += arr[i];
        }
        
        for(int i = 0; i < arr.size(); i++){
            if(leftSum == totalSum - arr[i]){
                return i;
            }
            leftSum += arr[i];
            totalSum -= arr[i];
        }
        
        return -1;
    }
};