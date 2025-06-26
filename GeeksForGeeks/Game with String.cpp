//link
//https://www.geeksforgeeks.org/problems/game-with-string4100/1

class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        if(k == s.length()){
            return 0;
        }
        
        vector<int> freq(26, 0);
        priority_queue<int> pq;
        for(auto& ch : s){
            freq[ch- 'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                pq.push(freq[i]);
            }
        }
        
        while(k > 0){
            int top = pq.top();
            pq.pop();
            if(top - 1 > 0){
                pq.push(top - 1);
            }
            k--;
        }
        int ans = 0;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            ans += (top * top);
        }
        
        return ans;
    }
};