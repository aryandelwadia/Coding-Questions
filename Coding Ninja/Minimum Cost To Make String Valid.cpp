//link
//https://www.naukri.com/code360/problems/minimum-cost-to-make-string-valid_1115770

#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  // Write your code here
  if(str.length() % 2 != 0){
    return -1;
  }

  stack<char> st;

  for(int i = 0; i < str.length(); i++){
    char ch = str[i];
    if(ch == '{'){
      st.push(ch);
    }
    else{
      if(st.empty()){
        st.push(ch);
      }
      else{
        char top = st.top();
        if(top == '{'){
          st.pop();
        }
        else{
          st.push(ch);
        }
      }
    }
  }

  int openCount = 0, closeCount = 0;
    while (!st.empty()) {
        if (st.top() == '{') {
            openCount++;
        } else {
            closeCount++;
        }
        st.pop();
    }

  int minimumCost = (openCount + 1) / 2 + (closeCount + 1) / 2;
  return minimumCost;
}