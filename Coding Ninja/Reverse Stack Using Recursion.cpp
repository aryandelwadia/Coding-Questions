//Link
//https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875

#include <bits/stdc++.h>

void bottom(stack<int> &stack, int num){
    if(stack.empty()){
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    bottom(stack, num);

    stack.push(n);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    bottom(stack, num);
}