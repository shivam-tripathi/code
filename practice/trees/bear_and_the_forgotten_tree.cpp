// http://codeforces.com/problemset/problem/639/B

#include <bits/stdc++.h>
using namespace std;

int n, d, h;
bool visited[100010];

int main(int argc, char const *argv[])
{
	cin >> n >> d >> h;

	if (d > 2*h || d < h || (n > 2 && h==d && d==1)) {
		cout << -1 << endl;
		return 0;
	}

	int nec = h;
	// if (d>h) {
	// 	nec = d-h;
	// }
	// else {
	// 	nec = d;
	// }

	int prev = 1, point = 2;
	visited[prev] = true;
	int dup = n-nec-1;

	while(nec && point <= n) {
		if (visited[point])  {
			point++;
			continue;
		}
		cout << prev << " " << point << endl;
		visited[point] = true;
		nec--;
		prev = point;
		point++;
	}

	if (h == d && n > 1) {
		for(int i=1; i<=n; i++) {
			if(!visited[i]) {
				visited[i] = true;
				cout << 2 << " " << i << endl;
			}
		}
	}
	else {
		h = d-h;
		while(dup) {
			nec = (dup > h) ? h : dup;
			dup -= nec;

			prev = 1;
			while(nec && point<=n) {
				if(visited[point]) {
					point++;
					continue;
				}
				cout << prev << " " << point << endl;
				visited[point] = true;
				nec--;
				prev = point;
				point++;
			}
		}
	}
	return 0;
}