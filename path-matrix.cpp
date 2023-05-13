#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;
int main() {
    ll n;
    cout << "Enter the number of Vertex:\n";
    cin >> n;
    vector<vector<ll>> mt(n, vector<ll>(n,0));

    auto pm = mt;
    cout << "Enter the graph:\n";
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            cin >> mt[i][j];
            // scanf
        }
    }
    for(ll k=0; k<n; k++) {
        for(ll i=0; i<n; i++) {
            for(ll j=0; j<n; j++) {
                mt[i][j]= mt[i][j] or (mt[i][k] and mt[k][j]); 
                
            }
        }
    }
    cout << "The path Matrix is:\n";
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            cout << mt[i][j] << " ";
        }
        cout << nl;
    }
}