//Link
//https://www.naukri.com/code360/problems/left-rotate-an-array-by-one_5026278

#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    for (int i = 0; i < n - 1; i++){
        swap(arr[i], arr[i + 1]);
    }

    return arr;
}
