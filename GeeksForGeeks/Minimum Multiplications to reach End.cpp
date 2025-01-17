//link
//https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        unordered_set<int> visited;
        visited.insert(start);
        
        queue<pair<int, int>> q;
        q.push({0, start});
        int steps = -1;
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int move = front.first;
            int num = front.second;
            
            if(num == end){
                return move;
            }
            
            for(int i = 0; i < arr.size(); i++){
                int m = (arr[i] * num) % 100000;
                if (visited.find(m) == visited.end()) {
                    visited.insert(m);
                    q.push({move + 1, m});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends