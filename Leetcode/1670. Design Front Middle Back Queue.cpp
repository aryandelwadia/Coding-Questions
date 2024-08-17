//link
//https://leetcode.com/problems/design-front-middle-back-queue/description/

class FrontMiddleBackQueue {
public:
    deque<int> dq;
    
    FrontMiddleBackQueue() { }
    
    void pushFront(int val) {
        dq.push_front(val);
    }
    
    void pushMiddle(int val) {
        int n = dq.size();
        auto it = dq.begin() + n / 2;
        dq.insert(it, val);
    }
    
    void pushBack(int val) {
        dq.push_back(val);
    }
    
    int popFront() {
        if(dq.empty()) {
            return -1;
        }
        int ans = dq.front();
        dq.pop_front();
        return ans;
    }
    
    int popMiddle() {
        if(dq.empty()) {
            return -1;
        }
        int n = dq.size();
        auto it = dq.begin() + (n - 1) / 2;
        int ans = *it;
        dq.erase(it);
        return ans;
    }
    
    int popBack() {
        if(dq.empty()) {
            return -1;
        }
        int ans = dq.back();
        dq.pop_back();
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
