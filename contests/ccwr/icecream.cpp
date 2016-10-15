#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int cost[n];
		for (int i = 0; i < n; ++i){
			cin >> cost[i];
		}
		sort(cost, cost+n-1);
		int w, y;
		cin >> w >> y;
		if(y > w || y > n){
			cout << "Not possible" << endl;
			continue;
		}
		int ans=0;
		while(--y){
			ans += cost[y];
			w--;
		}
		ans += w*cost[0];
		cout << ans << endl;
	}
	return 0;
}