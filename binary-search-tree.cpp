#include<bits/stdc++.h>
using namespace std; 
#define ll long long
struct node {
    ll val;
    node * left;
    node * right;
    node(int vl) {
        this->val = vl;
        left = right = NULL;
    }
};
node * root =NULL;
node * insert_rec(ll val, node * tmp) {
    if(tmp == NULL) {
        return new node(val);
    }
    if(tmp->val < val) {
        tmp->right = insert_rec(val, tmp->left);
    } else {
        tmp->left =  insert_rec(val, tmp->right);
    }
    return tmp;
}
void del( ll vl) {
    node * cr = root;
    while(cr->val) {
        
    }
}
bool search_rec (ll vl, node * cur = root) { 
    bool rs = false;
    if(cur == NULL) {
        return false;
    } else if( vl == cur->val ){
        return true;
    } else if (cur->val > vl) {
        rs = search_rec(vl, cur->left);
    } else if(cur->val < vl) {
        rs = search_rec(vl, cur->right);
    }
    return rs;
}

bool search_itr(ll vl) {
    node * cur = root;
    while(cur != NULL) {
        if(cur->val == vl) {
            return true;
        } else if(cur->val > vl) {
            cur = cur->left;
        } else if (cur->val < vl) {
            cur = cur->right;
        }
    }
    return false;
}

void insert_itr(ll val) {
    if (root== NULL) {
        root = new node(val);
        
    } else {
        node * tmp = root;
        while(1) {
            if(tmp->val > val) {
                if(tmp->left != NULL)
                    tmp = tmp->left;
                else
                    break;
            } else {
                if(tmp->right != NULL)
                    tmp = tmp->right;
                else break;
            }
        }
        if(val>tmp->val) {
            tmp->right = new node(val);
        } else {
            tmp->left = new node(val);
        }
    }
}
void print(node * cr, ll ort) {
    if(cr==NULL) {
        return;
    }
    if(ort==1) {
        cout << cr->val << " ";

    }
    print(cr->left, ort);
    if(ort==2) {
        cout << cr->val << " ";
    }
    print(cr->right, ort);
    if(ort==3) {
        cout << cr->val << " ";
    }
}
int main() {
    cout << "Enter Number of nodes:";
    ll n; cin >> n;
    for(ll i=0; i<n; i++) {
        ll x; cin >> x;
        insert_itr(x);
    }
    cout << "Enter -1 to exit.\n";
    while(1) {
        cout << "Enter operation type:\n";
        cout << "1. Insert\n";
        cout << "2. print\n";
        cout << "3. search\n";
        ll tp;
        cin >> tp;
        if(tp==1) {
            ll vl; cin >> vl;
            insert_itr(vl);
        } else if(tp==2) {
            ll ort;
            cout << "1. Enter 1 for preorder\n";
            cout << "2. Enter 2 for inorder\n";
            cout << "3. Enter 3 for postorder\n";

            cin >> ort;
            if(ort == 1) {
                cout << "Preorder traversal: \n";
                print(root, 1);
            } else if(ort== 2) {
                cout << "Inorder traversal: \n";
                print(root, 2);
            } else if(ort==3) {
                cout << "Postorder traversal: \n";
                print(root, 3);
            }
            cout << endl;
        } else if(tp==3) {
            ll vl; cin >> vl;
            bool fnd = search_itr(vl);
            if(fnd) {
                cout << "Found\n";
            } else {
                cout << "Not Found\n";
            }
        } else if(tp==-1) {
            break;
        }
    }
    // cout << ""
}