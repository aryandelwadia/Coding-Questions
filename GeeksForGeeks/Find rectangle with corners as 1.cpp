//link
//https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1

class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        unordered_set<string> s;
        for(int i = 0; i < n; i++){
            vector<int> cols;
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    cols.push_back(j);
                    
                }
            }
            
            for(int x = 0; x < cols.size(); x++){
                for (int y = x + 1; y < cols.size(); y++){
                    string valid = to_string(cols[x]) + "_" + to_string(cols[y]);
                    
                    if(s.count(valid)){
                        return true;
                    }
                    
                    s.insert(valid);
                }
            }
        }
        
        return false;
    }
};