//link
//https://www.geeksforgeeks.org/problems/decode-the-string2444/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<int> nums;
        stack<string> strings;
        string str = "";
        int count = 0;
        
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(isdigit(ch)){
                count = count * 10 + (ch - '0');
            }
            else if(ch == '['){
                nums.push(count);
                strings.push(str);
                str = "";
                count = 0;
            }
            else if(ch == ']'){
                int n = nums.top();
                nums.pop();
                
                string print = strings.top();
                strings.pop();
                
                for(int j = 0; j < n; j++){
                    print += str;
                }
                str = print;
                
            }
            else{
                str += ch;
            }
        }
        
        return str;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends