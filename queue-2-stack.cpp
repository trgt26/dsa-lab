/**
 * Implement queue using two stack
*/

#include<bits/stdc++.h>
using namespace std;

stack<int> st1, tmp;

void push(int vl) {
    while(!st1.empty()) {
        tmp.push(st1.top());
        st1.pop();
    }
    tmp.push(vl);
    while(!tmp.empty()) {
        st1.push(tmp.top());
        tmp.pop();
    }
}
int front() {
    return st1.top();
}

void pop() {
    st1.pop();
}

int main() {
    // cout << "Enter The size:\"
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        push(x);
    }
    cin >> n;
    while(n--) {
        cout << top() << " ";
        pop();
    }
    // while(1) {
    //     cout << "1. Insert\n;"
    //     if()
    // }
}