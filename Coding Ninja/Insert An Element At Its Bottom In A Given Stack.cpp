//Link
//https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

#include <bits/stdc++.h> 

void bottom(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int top = myStack.top();
    myStack.pop();

    bottom(myStack, x);

    myStack.push(top);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    bottom(myStack, x);

    return myStack;
}
