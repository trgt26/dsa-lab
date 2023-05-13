/**
 * Implement stack using two queue
*/
#include<bits/stdc++.h>
using namespace std;
queue<int> q1, q2;
void push(int vl) {
    q2.push(vl);
    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    while(!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
}
void pop() {
    q1.pop();
}
int top() {
    return q1.front();
}
int main() {
    while(1) {
        cout << "Enter your choice: " << endl;
        cout << "1. Push" << endl;
        cout << "2. top" << endl;
        cout << "3. pop" << endl;
        cout << "4. exit" << endl;
        int ch; cin >> ch;
        if(ch==1) {
            int vl; cin >> vl;
            push(vl);
        } else if(ch==2) {
            cout << top() << endl;
        } else if(ch==3) {
            pop();
        } else if(ch==4) {
            break;
        }
    }
}