//link
//https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    map<char, int> alphabets;
		    queue<char> q;
		    string ans = "";
		    
		    for(int i = 0; i < A.length(); i++){
		        
		        char ch = A[i];
		        
		        alphabets[ch]++;
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(alphabets[q.front()] > 1){
		                q.pop();
		            }
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends