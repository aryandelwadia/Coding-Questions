//link
//https://www.naukri.com/code360/problems/maximum-frequency-number_920319

#include<bits/stdc++.h>
int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int, int> m;
    int maxfreq = 0;
    int maxnum = INT_MIN;

    for(int i = 0; i < arr.size(); i++){
        m[arr[i]]++;
        maxfreq = max(maxfreq, m[arr[i]]);
    }

    for(int i = 0; i < arr.size(); i++){
        if(m[arr[i]] == maxfreq){
            maxnum = arr[i];
            break;
        }
    }

    return maxnum;
}