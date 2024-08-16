//link
//https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size();
        int element;
        for(int i = 0; i < n - 1; i++){
            element = q.front();
            q.pop();
            q.push(element);
        }

        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        int n = q.size();
        int element;
        for(int i = 0; i < n ; i++){
            element = q.front();
            q.pop();
            q.push(element);
        }

        return element;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */