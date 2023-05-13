#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cerr << #x << " " << x << "\n";
using namespace std;
ll n = 4;
vector<vector<ll>> mt(n, vector<ll>(n, INT_MAX));
vector<vector<ll>> nxt(n, vector<ll>(n, INT_MAX));
// vector<ll> find_path(ll i, ll j) {
//     vector<ll> path = {i};
    
// }
string find_path(int i, int j) {
    string path = string("") + (char)(i+'A');
    if(mt[i][j] == INT_MAX) {
        return "Not found";
    }
    // dbg(mt[i][j])
    // return " ";
    while(nxt[i][j] != j) {
        path += (char)(nxt[i][j] + 'A');
        i = nxt[i][j];
    }
    return path;
}

int main() {
    cin >> n;
    mt.assign(n, vector<ll>(n, INT_MAX));
    nxt.assign(n, vector<ll>(n, INT_MAX));
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            cin >> mt[i][j];
            nxt[i][j] = j;
        }
    }
    for(ll k=0; k<n; k++) {
        for(ll i=0; i<n; i++) {
            for(ll j=0; j<n; j++) {
                if(
                    (mt[i][k] != 0 and mt[k][j] != 0) and
                    (mt[i][j] == 0 or mt[i][j] > mt[i][k] + mt[k][j])
                ) {
                    mt[i][j] = mt[i][k] + mt[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    for(auto e : mt) {
        for(auto f : e) {
            cerr<< f << " ";
        }
        cerr << "\n";
    }
    cout << find_path(0, 3) << endl;

}