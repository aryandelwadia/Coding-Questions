//link
//https://www.naukri.com/code360/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465

class SpecialStack {
        stack<int> st;
        stack<int> min;
    
    public:
    void push(int data) {
        // Implement the push() function.
        if(min.empty() || data <= min.top()){
            min.push(data);
        }
        st.push(data);
    }

    void pop() {
        // Implement the pop() function.
        if(min.top() == st.top()){
            min.pop();
        }
        
        st.pop();
    }

    int top() {
        // Implement the top() function.
        return st.top();
    }

    int getMin() {
        // Implement the getMin() function.
        return min.top();
    }  
};