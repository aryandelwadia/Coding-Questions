//link
//https://www.naukri.com/code360/problems/nth-fibonacci-number_74156

#include<bits/stdc++.h>
using namespace std;

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin >> n;

        int prev1 = 0;
        int prev2 = 1;
        int curr;

        for(int i = 2; i <= n; i++){
                curr = prev1 + prev2;
                prev1 = prev2;
                prev2 = curr; 
        }
        cout << prev2 << endl;
        return 0;
}