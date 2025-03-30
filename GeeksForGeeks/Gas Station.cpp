//link
//https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

class Solution {
    public:
      int startStation(vector<int> &gas, vector<int> &cost) {
          // Your code here
          int totalGas = 0;
          int totalCost = 0;
          int currGas = 0;
          int start = 0;
          
          for(int i = 0; i < gas.size(); i++){
              totalGas += gas[i];
              totalCost += cost[i];
              currGas += gas[i] - cost[i];
              
              if(currGas < 0){
                  start = i + 1;
                  currGas = 0;
              }
          }
          
          if(totalGas < totalCost){
              return -1;
          }
          else{
              return start;
          }
      }
  };