/**
 * Implement queue using one stack
*/
#include<bits/stdc++.h>
using namespace std;
stack<int> st;
void push(int vl) {
    int n = st.size();
    for(int i=0; i<n; i++) {
        int tp = st.top();
        st.pop();
        st.push(tp);
    }
    st.push(vl);

}
int main() {

}