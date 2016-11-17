// http://www.spoj.com/problems/PARTY

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int N, W;
int val[110];
int wt[110];
pii dp[110][510];
int _dp[110][510];

pii solve(int n, int w){
	if(n >= N || w <= 0) return pii(0,0);

	if(dp[n][w].second != -1) return dp[n][w];
		
	pii temp1 = solve(n+1, w);
	if(w < wt[n]) 
		dp[n][w] = temp1;
	else {
		pii temp2 = solve(n+1, w-wt[n]);
		temp2.first += wt[n];
		temp2.second += val[n];
		if(temp2.second == temp1.second)
			dp[n][w] = (temp2.first < temp1.first) ? temp2 : temp1;
		else 
			dp[n][w] = (temp2.second > temp1.second) ? temp2 : temp1; 
	}

	return dp[n][w];
}

/*int _solve(int w, int i){
	if(i >= N || w <= 0)  return 0;

	if(_dp[i][w] != -1) 
		return _dp[i][w];

	if(w < wt[i]) 
		_dp[i][w] = _solve(w, i+1);
	else
		_dp[i][w] = max(val[i] + _solve(w-wt[i], i+1), _solve(w, i+1));

	return _dp[i][w];
}*/

int main(){
	while(true){
		cin >> W >> N;
		if(N+W == 0) break;

		for(int i=0; i<N; i++){
			cin >> wt[i] >> val[i];
		}
		memset(dp, -1, sizeof(dp));

		pii ans = solve(0, W);
		cout << ans.first << " " << ans.second << endl;
		
	}
    return 0;
}