//link
//https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1

class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < preorder.size(); ++i) {
            int count = 0;
            while (!st.empty() && preorder[i] > st.top()) {
                st.pop();
                count++;
            }
            if (count >= 2) {
                ans.push_back(preorder[i - 1]);
            }
            st.push(preorder[i]);
        }
        ans.push_back(preorder.back());

        return ans;
    }
};