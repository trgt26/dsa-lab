/**
 * Insertion in linear array
*/
#include<bits/stdc++.h>
using namespace std;

int arr[500];
int n = -1;
void insert(int pos=-1) {

    int vl;
    cin >> vl;
    if(pos==-1) {
        n++;
        arr[n] = vl;
    } else {
        pos--;
        for(int i=n+1;i>pos; i--) {
            arr[i] = arr[i-1];
        }
        n++;
        arr[pos] = vl;
    }
}
void print() {
    for(int i=0; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {

    for(;1;) {
        
        printf("Enter the type of insertion:\n");
        cout << "1. For inserting in back." << endl;
        cout << "2. For inserting in middle." << endl;
        cout << "3. For Inserting in front." << endl;
        cout << "4. For Printing the array" << endl;
        int ch; cin >> ch;
        if(ch==1) {
            insert();
        } else if(ch==2){
            int pos; cin >> pos;
            insert(pos);
        } else if(ch==3) {
            insert(1);
        } else if(ch==4) {
            print();
        }
    }
}