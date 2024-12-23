#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};


class Stack {
    public:
    Node* tp;
    Stack() {
        tp = NULL;
    }
    bool isEmpty() {
        return tp == NULL;
    }
    // No concept of full in LL implementation

    void push(int val) {
        Node* n_node = new Node(val);
        if (isEmpty()) {
            tp = n_node;
            return;
        }
        n_node->next = tp;
        tp = n_node;
    } // O(1)

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty" <<endl;
            return;
        }
        Node* temp = tp;
        tp = tp->next;
        delete temp; // Free the memory
    } // O(1)
    int top() {
        if (isEmpty()) {
            cout << "Stack is Empty" <<endl;
            return -10000000;
        }
        return tp->val;
    } // O(1)
};

int main() {
    Stack st = Stack();
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    while (!st.isEmpty()) {
        cout << st.top() <<endl;
        st.pop();
    }
}