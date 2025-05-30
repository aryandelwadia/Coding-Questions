//link
//https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void dfs(Node *root, int currSum, int currLen, int& maxSum, int& maxLen){
        if(root == NULL){
            return;
        }
        
        currLen += 1;
        currSum += root -> data;
        
        if(root -> left == NULL && root -> right == NULL){
            if(currLen > maxLen){
                maxLen = currLen;
                maxSum = currSum;
            }
            else if(currLen == maxLen && currSum > maxSum){
                maxSum = currSum;
            }
        }
        
        dfs(root -> left, currSum, currLen, maxSum, maxLen);
        dfs(root -> right, currSum, currLen, maxSum, maxLen);
    }
  
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int maxSum = 0;
        int maxLen = 0;
        
        dfs(root, 0, 0, maxSum, maxLen);
        return maxSum;
    }
};