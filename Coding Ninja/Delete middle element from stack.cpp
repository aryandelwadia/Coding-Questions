//Link
//https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246

#include <bits/stdc++.h> 

void middle(stack<int> &inputStack, int count, int N){
   if(count == N / 2){
      inputStack.pop();
      return;
   }
   
   int num = inputStack.top();
   inputStack.pop();

   middle(inputStack, count+1, N);

   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count = 0;
   middle(inputStack, count, N);
}