#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ll n, c;
	// scanf("%lld %lld", &n, &c);
	cin >> n >> c;
	ll prev, present;
	ll count = 0;
	for(ll i=0; i<n; i++){
		// scanf("%lld", &present);
		cin >> present;
		if(i==0){prev = present; count += 1; continue;}
		if((present - prev) > c){
			count = 1;
		}
		else 
			count += 1;
		prev = present;
	}
	// printf("%lld\n", count);
	cout << count << endl;
	return 0;
}