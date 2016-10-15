#include <bits/stdc++.h>
#define ll long long
#define mod (1000000000+7)
#define SIZE (100000+3)
using namespace std;

ll fact[SIZE];

ll power(ll a, ll b){
	ll x = 1, y = a;
	while (b > 0){
		if (b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}

ll modular_inverse(ll n){
	return power(n, mod-2);
}

ll nCr(ll n, ll k){
	return (fact[n]*((modular_inverse(fact[k]*modular_inverse(fact[n-k]))%mod))%mod);
}

int main(){
	fact[0] = 1;
	for(int i=1; i<11; i++){
		fact[i] = ((i%mod)*fact[i-1])%mod;
	}
	for(int i = 0; i<=10; i++){
		for(int j=0; j<=i; j++){
			cout << nCr(i,j) << " ";
		}
		cout << endl;
	}
}
