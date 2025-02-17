//link
//https://leetcode.com/problems/letter-tile-possibilities

class Solution {
    private:
        void solve(unordered_map<char, int> &letter, set<string> &combinations, string str){
            if(!str.empty()){
                combinations.insert(str);
            }
    
            for(auto &pair : letter){
                if(pair.second > 0){
                    pair.second--;
                    solve(letter, combinations, str + pair.first);
                    pair.second++;
                }
            }
    
        }
    
    public:
        int numTilePossibilities(string tiles) {
            set<string> combinations;
            unordered_map<char, int> letter;
            for(int i = 0; i < tiles.size(); i++){
                char c = tiles[i];
                letter[c]++;
            }
            solve(letter, combinations, "");
            return combinations.size();
        }
    };