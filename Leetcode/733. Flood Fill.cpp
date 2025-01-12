//link
//https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int m = image.size();
        int n = image[0].size();
        int start = image[sr][sc];

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while(!q.empty()){
            pair<int, int> front = q.front();
            q.pop();

            int r = front.first;
            int c = front.second;
            image[r][c] = color;

            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >=0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == start && image[nr][nc] != color){
                    q.push({nr, nc});
                }
            }

        }

        return image;
    }
};