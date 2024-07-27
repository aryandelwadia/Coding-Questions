//Link
//https://www.naukri.com/code360/problems/stocks-are-profitable_893405

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    if (n == 0){
        return 0;
    }
    
    int minPrice = prices[0];
    int profit = 0;
    
    for (int i = 1; i < n; i++) {
        profit = max(profit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    
    return profit;
}