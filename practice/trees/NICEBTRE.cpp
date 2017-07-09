// http://www.spoj.com/problems/NICEBTRE
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

string str;
int t, test;

pii solve(int i) {
	// cout << "index " << i << endl;

	if (i >= str.size())
		return pii(0,i);

	if (str[i] == 'l') {
		i++;
		return pii(1, i);
	}

	pii l = solve(i+1);
	pii r = solve(l.second);

	// cout << "Tree rooted at " << i << " left ans " << l.first << " right ans " << r.first << endl;

	return pii(max(l.first, r.first) + 1, r.second);
}

int main() {
	cin >> t;
	test = t;
	while(t--) {
		cin >> str;
		int i = 0;
		pii ans = solve(i);
		// cout << "Ans " << (test-t) << "\n" << ans.first-1 << endl;
		cout << ans.first-1 << endl;
	}
}
