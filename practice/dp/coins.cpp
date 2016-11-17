// http://www.spoj.com/problems/COINS/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

#define SIZE 1000000010

map<int, ll> dp;

void solve(int i=SIZE){
	if(i<0 || i == 0 || i == 1) return;
	if(!dp[i]) {
		dp[i] = i;
		solve(i/2);
		solve(i/3);
		solve(i/4);
		ll ans = dp[i/2] + dp[i/3] + dp[i/4];
		if(i < ans)	dp[i] = ans;
	}
}

int main(){
    dp[0] = 0;
    dp[1] = 1;
    ll n;
    while(scanf("%lld",&n)==1) {
    	solve(n);
    	cout << dp[n] << endl;
    }
    return 0;
}