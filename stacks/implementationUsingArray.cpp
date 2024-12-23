// STACK => Data Structure with LIFO (Last In First Out) property
// Operations: Push, Pop, Top, isEmpty, isFull
// Implementation using Array

#include<bits/stdc++.h>
using namespace std;

class Stack {
    public:
    int* arr;
    int tp;
    int size;
    Stack() {
        arr = new int[1000];
        tp = -1;
        size = 1000;
    }
    Stack(int n) {
        arr = new int[n]; // Dynamic memory allocation please keep in mind
        tp = -1;
        size = n;
    }

    bool isEmpty() {
        return tp == -1;
    }

    bool isFull() {
        return tp == size - 1;
    }

    void push(int val ){
        if (!isFull()) {
            cout << "Stack is Full" <<endl;
            return;
        }
        arr[++tp] = val;
    }

    int pop () {
        if (!isEmpty()) {
            return arr[tp--];
        }
        cout << "Stack is Empty" <<endl;
        return -10000000;
    }

    int top() {
        if(!isEmpty()) {
            return arr[tp];
        }
        cout << "Stack is Empty" <<endl;
        return -10000000;
    }
};

int main() {
    Stack st1 = Stack(5);
    Stack st2  = Stack();
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    while(!st1.isEmpty()) {
        cout << st1.top() <<endl;
        st1.pop();
    }
}