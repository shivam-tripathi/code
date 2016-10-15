#include <bits/stdc++.h>
using namespace std;

void print(int a[], int size, int total){
    int blank = (total-size)/2;
    for(int i=0; i<blank; i++)
        cout << " ";
    for(int i = 0; i <= size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int nCrModp(int n, int r, int p){
    int c[n+1], temp, prev;
    memset(c,0,sizeof(c));
    c[0] = 1;
    for(int i=0; i<=n; i++){
        temp = 0;
        for(int j=0; j<=i; j++){
            // Here j must be till min(i,r), but as I am printing pascal's triangle I am doing it till i
            // I made this mistake of calculating all last time to get a TLE :P
            // To avoid using two temporary variable, process the array in reverse order
            // That way there will be no conflicts :)
            prev = c[j];
            c[j] = (temp%p+c[j]%p)%p;
            temp = prev;
        }
        print(c, i, n);
    }
    return c[r];
}

int main(){
    cout << "10C5 is " << nCrModp(10, 5, 1000) << endl;
}
