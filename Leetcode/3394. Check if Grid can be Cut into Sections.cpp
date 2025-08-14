//link
//https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> xdir, ydir;

        for(int i = 0; i < rectangles.size(); i++){
            vector<int> tempx, tempy;
            tempx.push_back(rectangles[i][0]);
            tempx.push_back(rectangles[i][2]);
            tempy.push_back(rectangles[i][1]);
            tempy.push_back(rectangles[i][3]);
            xdir.push_back(tempx);
            ydir.push_back(tempy);
        }

        sort(xdir.begin(), xdir.end());
        sort(ydir.begin(), ydir.end());

        vector<vector<int>> ansx;
        ansx.push_back(xdir[0]);
        for (int i = 1; i < xdir.size(); ++i) {
            vector<int>& last = ansx.back();
            if (xdir[i][0] < last[1]) {
                last[1] = max(last[1], xdir[i][1]);
            } 
            else{
                ansx.push_back(xdir[i]);
            }
        }
        if (ansx.size() >= 3) return true;
        
        vector<vector<int>> ansy;
        ansy.push_back(ydir[0]);
        for (int i = 1; i < ydir.size(); ++i) {
            vector<int>& last = ansy.back();
            if (ydir[i][0] < last[1]) {
                last[1] = max(last[1], ydir[i][1]);
            } 
            else{
                ansy.push_back(ydir[i]);
            }
        }
        if (ansy.size() >= 3) return true;

        return false;
    }
};