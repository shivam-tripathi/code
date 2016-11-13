#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int maze[100000+10];
int dp[100000+10];
int rowsolution[100000+10];
int m, n;

int solve(int* a, int i=0){
	if(i < 0 || i >= n)
		return 0;
	if(dp[i] != -1) return dp[i];
	dp[i] = max(a[i] + solve(a, i+2), solve(a, i+1));
	return dp[i];
}

int main(){
	while(true){
	    cin >> m >> n;
	    if(m+n == 0) break;
	    for(int i=0; i<m; i++){
	    	for(int j=0; j<n; j++){
	    		cin >> maze[j];
	    		dp[j] = -1;
	    	}
	    	rowsolution[i] = solve(maze);
	    }
	    for(int i=0; i<m; i++) dp[i] = -1;
		n = m;
	    cout << solve(rowsolution) << endl;
	}
	return 0;
}