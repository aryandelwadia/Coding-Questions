//Link
//https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908

#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
public:

    Queue() {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == rear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear != size){
            arr[rear] = data;
            rear++;
        }
        return;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront == rear){
            return -1;
        }
        int n = arr[qfront];
        qfront++;
        if(qfront == rear){
            qfront = 0;
            rear = 0;
        }
        return n;
    }

    int front() {
        // Implement the front() function
        if (qfront == rear){
            return -1;
        }
        return arr[qfront];
    }
};