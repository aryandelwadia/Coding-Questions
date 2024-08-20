//link
//https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l != r){
            int bredth = r - l;
            int lenght = min(height[r], height[l]);
            int newArea = lenght * bredth;
            if(newArea > maxarea){
                maxarea = newArea;
            }
            if(height[l] > height[r]){
                r--;
            }
            else{
                l++;
            }
        }

        return maxarea;
    }
};