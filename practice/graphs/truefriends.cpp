// http://www.spoj.com/problems/TFRIENDS/

#include <bits/stdc++.h>
using namespace std;

int n;

bool grid[110][110];
bool revgrid[110][110];
bool visited[110];
stack<int> stck;

bool flag;
void dfs(int src, bool mat[110][110]) {
	// cout << "> > " << src << endl;
	visited[src] = true;
	for(int i=0; i<n; i++) {
		if (mat[src][i] && !visited[i]) {
			dfs(i, mat);
		}
	}
	if (flag) stck.push(src);
}


int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		memset(grid, 0, sizeof grid);
		memset(grid, 0, sizeof revgrid);
		memset(visited, false, sizeof visited);
		while(!stck.empty()) stck.pop();

		string s;
		for(int i=0; i<n; i++) {
			cin >> s;
			for(int j=0; j<n; j++) {
				if (s[j] == 'Y') {
					grid[i][j] = revgrid[j][i] = true;
				}
				else {
					grid[i][j] = revgrid[j][i] = false;
				}
			}
			// visited[i] = false;
		}

		flag = true;
		for(int i=0; i<n; i++) {
			if (!visited[i]) {
				// cout << i << endl;
				dfs(i, grid);
			}
		}

		int ans = 0;
		flag = false;
		memset(visited, 0, sizeof visited);
		while(!stck.empty()) {
			if (!visited[stck.top()]) {
				// cout << "\t Popped now " << stck.top() << endl;
				dfs(stck.top(), revgrid);
				ans++;
			}
			stck.pop();
		}

		// cout << "## " << ans << endl;
		cout << ans << endl;

	}

	return 0;
}