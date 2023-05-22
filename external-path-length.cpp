#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr << #x << " " << x << "\n";
struct node {
    int val;
    node * lft;
    node * rt;
    node(int vl) {
        val = vl;
        lft = rt = NULL;
    }
};

node * root = NULL;

node * insert_rec(int val, node * tmp) {
    if(tmp == NULL) {
        return new node(val);
    }
    if(tmp->val < val) {
        tmp->rt = insert_rec(val, tmp->rt);
    } else {
        tmp->lft =  insert_rec(val, tmp->lft);
    }
    return tmp;
}

int sm = 0;
void external_path(node * cr, int lvl) {
    if(cr->lft == NULL and cr->rt == NULL) {
        sm += lvl;
        
    }
    if(cr->lft != NULL) {
        external_path(cr->lft, lvl+1);
    }

    if(cr->rt != NULL) {
        external_path(cr->rt, lvl+1);
    }
}
void print(node * cr) {
    if(cr==NULL) {
        return;
    }
    
    cout << cr->val << " ";
    print(cr->lft);

    print(cr->rt);

}
int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int x; cin >> x;
        root = insert_rec(x, root);
  
    }

    print(root);
    external_path(root, 0);
    dbg(sm)
}