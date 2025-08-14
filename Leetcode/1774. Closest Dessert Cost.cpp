//link
//https://leetcode.com/problems/closest-dessert-cost/description/

class Solution {
public:
    void solve(vector<int>& toppingCosts, int i, int base, int target, int& ans){
        if(abs(base - target) < abs(ans - target) || (abs(base - target) == abs(ans - target) && base < ans)){
            ans = base;
        }

        if(i >= toppingCosts.size()){
            return;
        }

        solve(toppingCosts, i + 1, base, target, ans);
        solve(toppingCosts, i + 1, base + toppingCosts[i], target, ans);
        solve(toppingCosts, i + 1, base + (2 * toppingCosts[i]), target, ans);
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = INT_MAX;
        for(int i = 0; i < baseCosts.size(); i++){
            solve(toppingCosts, 0, baseCosts[i], target, ans);
        }
        return ans;
    }
};