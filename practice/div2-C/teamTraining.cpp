// http://codeforces.com/problemset/problem/519/C

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int m, n, groups, ans=0;
	cin >> m >> n;
	if (m > n) swap(m, n);

	int prevm=-1, prevn=-1;
	while (m && n) {
		if(m == prevm && n == prevn) break;
		prevm = m;
		prevn = n;
		if (n-2 < 0 || m-1 < 0)
			break;
		n -= 2;
		m--;
		ans++;
		if (m > n) swap(m, n);
	}
	cout << ans << endl;
}