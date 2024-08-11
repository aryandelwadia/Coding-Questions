//Link
//https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:

    int nextGreaterElement(stack<int> st, int num){
        while(st.top() != num){
            st.pop();
        }
        st.pop();
        while(!st.empty()){
            if(st.top() > num){
                return st.top();
            }
            st.pop();
        }

        return -1;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans;

        for(int i = nums2.size() - 1; i >= 0; i--){
            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(nextGreaterElement(st, nums1[i]));
        }

        return ans;
    }
};