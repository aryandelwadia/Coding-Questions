//Link
//https://www.naukri.com/code360/problems/sort-a-stack_985275

#include <bits/stdc++.h>

void insert(stack<int> &stack, int num) {
  if (stack.empty() || (stack.top() < num)) {
    stack.push(num);
    return;
  }

  int n = stack.top();

  stack.pop();
  insert(stack, num);
  stack.push(n);
}

void sortStack(stack<int> &stack) {
  // Write your code here

  if (stack.empty()) {
    return;
  }

  int num = stack.top();
  stack.pop();

  sortStack(stack);

  insert(stack, num);
}