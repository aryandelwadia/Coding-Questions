//link
//https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies, candies + N);
        int low = 0;
        int n = N;
        int i = 0;
        while(n > 0){
            if(i >= N){
                break;
            }
            low += candies[i];
            i++;
            n -= K + 1;
        }
        
        int high = 0;
        n = N;
        i = N - 1;
        while(n > 0){
            if(i < 0){
                break;
            }
            high += candies[i];
            i--;
            n -= K + 1;
        }
        
        return {low, high};
    }
};
