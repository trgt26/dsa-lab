#include<stdio.h>
#define ll long long


char path[100];
int l = 0;
int n;

void find_path(int i, int j, int nxt[][n], int mt[][n]) {
    if(mt[i][j] == 0) {
        return ;
    }


    path[0] = (char)(i+'A');
    l++;


    while(nxt[i][j] != j) {
        path[l]= (char)(nxt[i][j] + 'A');
        l++;
        i = nxt[i][j];
    }
    path[l]= (char)(j+'A');
    l++;

}

int main() {
    scanf("%d", &n);
    int mt[n][n];
    int nxt[n][n];
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            scanf("%d", &mt[i][j]);
            nxt[i][j] = j;
        }
    }
    for(ll k=0; k<n; k++) {
        for(ll i=0; i<n; i++) {
            for(ll j=0; j<n; j++) {
                if(
                    (mt[i][k] != 0 && mt[k][j] != 0) &&
                    (mt[i][j] == 0 || mt[i][j] > mt[i][k] + mt[k][j])
                ) {
                    mt[i][j] = mt[i][k] + mt[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    find_path(0, 4, nxt, mt) ;
    for(int i= 0; i<l; i++) {
        printf("%c", path[i]);
    }

}

