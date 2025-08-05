//link
//https://leetcode.com/problems/fruits-into-baskets-ii/description

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(baskets[j] != -1 && fruits[i] <= baskets[j]){
                    baskets[j] = -1;
                    count++;
                    break;
                }
            }
        }

        return n - count;
    }
};