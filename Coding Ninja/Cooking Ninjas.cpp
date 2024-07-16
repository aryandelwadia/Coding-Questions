//Link
//https://www.naukri.com/code360/problems/cooking-ninjas_1164174

#include <bits/stdc++.h> 
bool calculateDish(vector<int> &rank, int m, int n, int mid){
    int dish = 0;

    for (int i = 0; i < n; i++){
        int j = 0;
        int timetaken = 0;

        while(timetaken + (rank[i] * (j + 1)) <= mid){
            timetaken += (rank[i] * (j + 1));
            j++;
        }

        dish += j;

        if (dish >= m){
            return true;
        }
    }

    if (dish >= m){
        return true;
    }
    else{
        return false;
    }

}

int minCookTime(vector<int> &rank, int m)
{
    // Write your code here
    int s = 0;
    int e = 0;
    int n = rank.size();
    int ans = 0;

    sort(begin(rank), end(rank));

    int worst = rank[n - 1];

    e = worst * m * (m + 1) / 2;
    
    int mid = s + (e - s) / 2;

    while (s <= e){
        if(calculateDish(rank, m, n, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}
