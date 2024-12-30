#include<bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}
int main() {
    string s;
    cin >> s;
    stack<char>st;
    string ans;
    for (auto it : s) {
        if (it == '(') {
            st.push(it);
        } else if (it == ')') {
            while(!st.empty() && st.top() != '(') {
                ans.push_back(st.top());
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        } else if (it == '+' || it == '-' || it == '*' || it == '/' || it == '^') {
            while(!st.empty() && precedence(it) <= precedence(st.top())) {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(it);
        } else {
            ans.push_back(it);
        }
    }
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    cout << ans << endl;
}