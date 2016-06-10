#include <bits/stdc++.h>
#define MOD (1000000000+7)
#define SIZE (100000+3)
using namespace std;

long long fact[SIZE];

long long Combi(long long n, long long k){
    long long x = (fact[n-k]*fact[k])%MOD;
    return (fact[n]*(long long)pow(x, MOD-2))%MOD;
}

int main(){
    fact[0] = 1;
    for(int i=1; i<SIZE; i++){
        fact[i] = ((fact[i-1]%MOD)*(i%MOD))%MOD;
    }
    for(int i=0; i<10; i++)
        cout << fact[i] << " ";
    cout << endl;
    for(int i=1; i<10; i++){
        for(int j=0; j<=i; j++){
            cout << Combi(i,j) << "\t";
        }
        cout << endl;
    }
}

/*
int main(){
    long long t, n, k, temp;
    cin >> t;
    fact[0] = 1;
    for(int i=1; i<SIZE; i++){
        fact[i] = ((fact[i-1]%MOD)*(i%MOD))%MOD;
    }
    while(t--){
        cin >> n >> k;
        for(int i=0; i<n; i++)
            cin >> temp;
        temp = k;
        long long result=0;
        while(k>=0){
            result += Combi(n,k);
            k-=2;
        }
        cout << result << endl;
    }
}
*/
