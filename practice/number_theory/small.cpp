#include <bits/stdc++.h>
using namespace std;

#define SIZE 10000+2
#define MOD 1000000007
typedef long long ll;

int main(int argc, char const *argv[]){
	int t;
	scanf("%d", &t);

	int prime[SIZE] = {0};
	for(int i=2; i<SIZE; i++){
		if(prime[i] == 0){
			for(int j=i; j<SIZE; j+=i){
				prime[j] = i;
			}
		}
	}

	ll ans[SIZE];
	ans[0] = 0;
	ans[1] = 1;
	ll temp;
	int fact, point;


	for(int i=2; i<SIZE; i++){
		temp = MOD+ans[i-1];
		if(temp%i == 0){
			ans[i] = ans[i-1];
		}
		else{
			point = i;
			while(true){
				fact = prime[point];
				if(temp % fact != 0){
					ans[i] = (ans[i-1] * (fact%MOD) )%MOD;
					break;
				}
				else{
					temp = (temp/fact);
					point = point/fact;
				}
			}
		}
	}

	while(t--){
		int n;
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}
