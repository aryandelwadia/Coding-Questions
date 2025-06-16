//link
//https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1

class Solution {
  public:
    int solve(vector<int>& heights, vector<int>& cost, int mid){
        int ans = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            ans += abs(heights[i] - mid) * cost[i];
        }
        
        return ans;
    }
  
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n = heights.size();
        int low = INT_MAX;
        int high = INT_MIN;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            low = min(low, heights[i]);
            high = max(high, heights[i]);
        }
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            int c1 = solve(heights, cost, mid - 1);
            int c2 = solve(heights, cost, mid);
            int c3 = solve(heights, cost, mid + 1);
            
            if(c2 <= c1 && c2 <= c3){
                ans = c2;
                return ans;
            }
            else if(c1 >= c2 && c2 >= c3){
                low = mid + 1;
            }
            else if(c1 <= c2 && c2 <= c3){
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
