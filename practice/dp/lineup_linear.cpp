// http://www.spoj.com/problems/LINEUP/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int dp[11][1<<12], players[11][11];

int player_print;

int solve(int player, int status) {
	if(player >= 11) return 0;
	if(dp[player][status] == -1) {
		int ans = -inf, temp, index;
		for(int i=0; i<11; i++){
			if(status & (1<<i) || !players[player][i]) continue;
			temp = players[player][i] + solve(player+1, status | (1<<i));
			ans = (ans < temp ? temp : ans);
		}
		dp[player][status] = ans;
		
	} 
	return dp[player][status];
}

int main(){
    int t;
    cin >> t;
    while(t--){
    	for(int i=0; i<11; i++){
    		for(int j=0; j<11; j++){
    			cin >> players[i][j];
    		}
    	}
    	memset(dp, -1, sizeof(dp));
    	cout << solve(0, 0) << endl;
    }
    return 0;
}