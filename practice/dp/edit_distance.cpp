#include <bits/stdc++.h>
using namespace std;

string a, b;

// Attempt at tabulation


int dp[100][100];

int _edit_distance(){
	memset(dp, -1, sizeof dp);
	int m = a.size(), n = b.size();
	for(int i=m; i>=0; i--) {
		for(int j=n; j>=0; j--) {
			if (j == n) {
				dp[i][j] = max((int)a.size()-i, 0); 
				cout << i << " " << j << " -> " << dp[i][j] << " | ";
				continue;
			}
			if (i == m) {
				dp[i][j] = max((int)b.size()-j, 0);
				cout << i << " " << j << " -> " << dp[i][j] << " | ";
				continue;
			}
			if (a[i] == b[j]) {
				dp[i][j] = dp[i+1][j+1];
				cout << i << " " << j << " -> " << dp[i][j] << " | ";
				continue;
			}
			dp[i][j] = 1 + min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]));
			cout << i << " " << j << " -> " << dp[i][j] << " | ";
		}
	}
	cout << endl;
	return dp[0][0];
}
int edit_distance (int m = 0, int n = 0) {

	if (m > a.size() || n > b.size())
		return 0;

	if (dp[m][n] != -1)
		return dp[m][n];

	if (m == a.size()) {
		dp[m][n] = max((int)(b.size() - n), 0);
		return dp[m][n];
	}

	if (n == b.size()) {
		dp[m][n] = max((int)(a.size() - m), 0);
		return dp[m][n];
	}

	if (a[m] == b[n]) {
		dp[m][n] = edit_distance(m+1, n+1);
	}
	else {
		dp[m][n] = 1 + min(edit_distance(m+1, n), min(edit_distance(m, n+1), edit_distance(m+1, n+1))); 
	} 

	return dp[m][n];
}


int main(int argc, char const *argv[])
{
	cin >> a >> b;
	memset(dp, -1, sizeof dp);
	int temp = _edit_distance();

	for (int i=0; i<a.size(); i++) {
		for (int j=0; j<b.size(); j++) {
			cout << i << ", " << j << " : " << dp[i][j] << endl;
		}
	}

	cout << "Ans: " << temp << endl;

	return 0;
}