//link
//https://leetcode.com/problems/maximum-height-by-stacking-cuboids

class Solution {
    private:
        bool check(vector<int> &base, vector<int> &top){
            if(top[0] <= base[0] && top[1] <= base[1] && top[2] <= base[2]){
                return true;
            }
            return false;
        }
    
        int solve(int n, vector<vector<int>>& cuboids){
            vector<int> currRow(n + 1, 0);
            vector<int> nextRow(n + 1, 0);
    
            for(int curr = n - 1; curr >= 0; curr--){
                for(int prev = curr - 1; prev >= -1; prev--){
                    int include = 0;
                    if(prev == -1 || check(cuboids[curr], cuboids[prev])){
                        include = cuboids[curr][2] + nextRow[curr + 1];
                    }
                    int exclude = nextRow[prev + 1];
    
                    currRow[prev + 1] = max(include, exclude);
                }
                nextRow = currRow;
            }
    
            return nextRow[0];
        }
    
    public:
        int maxHeight(vector<vector<int>>& cuboids) {
            for(auto &a : cuboids){
                sort(a.begin(), a.end());
            }
    
            sort(cuboids.begin(), cuboids.end());
    
            return solve(cuboids.size(), cuboids);
        }
    };