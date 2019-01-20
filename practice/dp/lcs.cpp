#include <bits/stdc++.h>
using namespace std;

int cmp (char c, string a, int j) {
	for (int i=j; i<a.size(); i++) {
		if (c == a[i])
			return i;
	}
	return -1;
}

#define SIZE 50000+10

int dp[SIZE][SIZE];

int solve (string a, string b, int i, int j) {
	if (i >= a.size() || j >= b.size()) {
		return 0;
	}

	if (dp[j][i] != -1) 
		return dp[j][i];

	int index = cmp(a[i], b, j);

	int ans;
	int ans2 = solve(a, b, i+1, index+1);
	int ans1 = solve(a, b, i+1, j);

	ans = max(ans1, ans2+1);
	
	dp[j][i] = ans;
	return ans;
}


int main(int argc, char const *argv[])
{
	string a, b;
	
	cin >> a >> b;
	
	for (int i=0; i<b.size(); i++) {
		for (int j=0; j<a.size(); j++) {
			dp[i][j] = -1;
		}
	}

	cout << solve (a, b, 0, 0) << endl;

	return 0;
}