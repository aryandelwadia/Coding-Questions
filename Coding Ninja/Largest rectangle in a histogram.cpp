//link
//https://www.naukri.com/code360/problems/largest-rectangle-in-a-histogram_1058184

#include<bits/stdc++.h>

vector<int> prevSmallerElement(vector<int> arr, int n){
  stack<int> st;
  st.push(-1);
  vector<int> ans(n);

  for(int i = 0; i < n; i++){
    int curr = arr[i];
    while(st.top() != -1 && arr[st.top()] >= curr){
      st.pop();
    }
    ans[i] = st.top();
    st.push(i);
  }

  return ans;
}

vector<int> nextSmallerElement(vector<int> arr, int n){
  stack<int> st;
  st.push(-1);
  vector<int> ans(n);

  for(int i = n - 1; i >= 0; i--){
    int curr = arr[i];
    while(st.top() != -1 && arr[st.top()] >= curr){
      st.pop();
    }
    ans[i] = st.top();
    st.push(i);
  }

  return ans;
}

int largestRectangle(vector < int > & heights) {
  // Write your code here.

  int n = heights.size();
  int area = INT_MIN;

  vector<int> next(n);
  next = nextSmallerElement(heights, n);

  vector<int> prev(n);
  prev = prevSmallerElement(heights, n);

  for(int i = 0; i < n; i++){
    int l = heights[i];

    if(next[i] == -1){
      next[i] = n;
    }

    int b = next[i] - prev[i] - 1;
    int newArea = l * b;
    area = max(area, newArea);
  }

  return area;
}