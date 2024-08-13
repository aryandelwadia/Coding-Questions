//link
//https://leetcode.com/problems/design-circular-deque/

class MyCircularDeque {
private:
    int l;
    int r;
    int sz;
    int k;
    vector<int> deque;

public:
    MyCircularDeque(int k) {
        deque.resize(k, 0);
        l = r = 0;
        sz = 0;
        this->k = k;
    }
    
    bool insertFront(int value) {
        if (sz == k) return false;
        l = (l - 1 + k) % k;
        deque[l] = value;
        ++ sz;
        if (sz == 1) r = l;
        return true;
    }
    
    bool insertLast(int value) {
        if (sz == k) return false;
        r = (r + 1) % k;
        deque[r] = value;
        ++ sz;
        if (sz == 1) l = r;
        return true;
    }
    
    bool deleteFront() {
        if (sz == 0) return false;
        l = (l + 1) % k;
        -- sz;
        return true;
    }
    
    bool deleteLast() {
        if (sz == 0) return false;
        r = (r + k - 1) % k;
        -- sz;
        return true;
    }
    
    int getFront() {
        if (sz == 0) return -1;
        return deque[l];
    }
    
    int getRear() {
        if (sz == 0) return -1;
        return deque[r];
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz == k;
    }
};