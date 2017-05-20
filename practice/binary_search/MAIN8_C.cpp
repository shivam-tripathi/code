#include <bits/stdc++.h>
using namespace std;

const int size = (int)50000+100;
int box[size];
int n, k;

bool check(int x) {
	int temp = k;
	for (int i=0; i<n; i++) {
		temp = temp - (box[i]/x);
		if (temp <= 0)
			return true;
 	} 
	return false;
}


int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &k);
		
		int low=1, high=1, mid;
		
		for(int i=0; i<n; i++) {
			scanf("%d", &box[i]);
			high = max(high, box[i]);
		}

		int ans = 0;

		while (high	>= low) {
			mid = low + (high-low)/2;
			int val = check(mid);
			if (val) {
				ans = mid;
				low = mid+1;
			}
			else {
				high = mid-1;
			}
		}

		cout << ans << endl;
	}

	return 0;
}