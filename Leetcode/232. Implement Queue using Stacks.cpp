//link
//https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:

    stack<int> st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int n = st1.top();
        while(st1.size() != 1){
            n = st1.top();
            st1.pop();
            st2.push(n);
        }
        n = st1.top();
        st1.pop();

        while(!st2.empty()){
            int element = st2.top();
            st2.pop();
            st1.push(element);
        }

        return n;
    }
    
    int peek() {
        int n = st1.top();
        while(!st1.empty()){
            n = st1.top();
            st1.pop();
            st2.push(n);
        }

        while(!st2.empty()){
            int element = st2.top();
            st2.pop();
            st1.push(element);
        }

        return n;
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */