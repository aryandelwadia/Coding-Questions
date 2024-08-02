//Link
//https://www.naukri.com/code360/problems/k-largest-element_1062624

#include <bits/stdc++.h> 
vector<int> Klargest(vector<int> &a, int k, int n) {
    // Write your code here
    vector<int> ans;
    sort(a.begin(), a.end());

    for(int i = n - k; i < n; i++){
        ans.push_back(a[i]);
    }

    return ans;
}