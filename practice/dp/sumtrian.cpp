#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int dp[100+10];

int get_val(int i, int j){
	if(j < 0 || i == j) return 0;
	else return dp[j];
}

int main(){
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int t1, t2;
	    int i, j;

	    for(i=0; i<n; i++){
	    	for(j=0; j<=i; j++){
		    	cin >> t1;
		    	int add = 0;
		    	if(i+j != 0) {
		    		int x = get_val(i, j);
		    		int y = get_val(i, j-1);
		    		add = max(get_val(i, j), get_val(i, j-1));
		    	}
		    	t1+=add;
		    	if(j>0) dp[j-1] = t2;
		    	t2 = t1;
		    }
		    dp[j-1] = t2;
	    }	    
	    int ans=0;
	    for(int i=0; i<n; i++)
	    	if(dp[i] > ans)
	    		ans = dp[i];
	    cout << ans << endl;
	}
	return 0;
}