//link
//https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        for(int i = 0; i < arr.size(); i++){
            string s = arr[i];
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(s == "+"){
                    int s = a + b;
                    st.push(s);
                }
                if(s == "-"){
                    int s = a - b;
                    st.push(s);
                }
                if(s == "*"){
                    int s = a * b;
                    st.push(s);
                }
                if(s == "/"){
                    int s = a / b;
                    st.push(s);
                }
                
            }
            else{
                int n = stoi(s);
                st.push(n);
            }
        }
        
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends