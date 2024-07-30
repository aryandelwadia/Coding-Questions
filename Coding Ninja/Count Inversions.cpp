//Link
//https://www.naukri.com/code360/problems/count-inversions_615

#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long count = 0;

    for (int i = 0; i < n - 1; i++){
        for(int j = i; j < n; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }

    return count;
}