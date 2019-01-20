// http://codeforces.com/contest/545/problem/C

#include <bits/stdc++.h>
using namespace std;

const int size = 1e9;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	int pos[t+1];
	int hgt[t+1];
	for(int i=1; i<=t; i++) cin >> pos[i] >> hgt[i];

	int ans = (t==1) ? 1 : 2;
	for(int i=2; i<t; i++) {
		if (pos[i] - pos[i-1] > hgt[i]) { ans++; }
		else if (pos[i+1] - pos[i] > hgt[i]) { ans++; pos[i] += hgt[i]; }
	}

	cout << ans << endl;
	return 0;
}