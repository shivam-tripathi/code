// https://www.codechef.com/CCWR2016/problems/CCWR02

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int x;
		int  k;
		cin >> x >> k;
		int temp = x;
		int a[k];
		int b[k];
		for(int i=0; i<k; i++){
			cin >> a[i];
		}
		for(int i=0; i<k; i++){
			cin >> b[i];
		}
		for (int i = 0; i < k; ++i){
			int inc = x/b[i];
			inc *= a[i];
			x += inc;

		}
		double ans = 100.0 - (100.0*temp)/x;
		cout << ans << endl;
	}
}