#include <bits/stdc++.h>
using namespace std;

bool knowsArr[110][110];
int visited[110];

vector<int> st;
vector<int> rev;
int n;
int _count = 1;

void dfs(int src, bool stackPush) {
	if (src > n) return;
	visited[src] = _count;
	for (int i=1; i<=n; i++) {
		if (stackPush && knowsArr[src][i] && !visited[i]) {
			dfs(i, stackPush);
		}
		if (!stackPush && knowsArr[i][src] && !visited[i]) {
			dfs(i, stackPush);
		}
	}
	if (stackPush) { st.push_back(src); }
}


int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		st.clear();
		rev.clear();
		_count = 1;

		string str;
		for(int i=1; i<=n; i++) {
			cin >> str;
			visited[i] = 0;
			for(int j=1; j<=n; j++) {
				knowsArr[i][j] = (str[j-1] == 'Y');
			}
		}

		for (int i=1; i<=n; i++) {
			if (!visited[i]) dfs(i, true);
		}

		for (int i=0; i<=n; i++) visited[i] = 0;

		for (int i=n-1; i>=0; i--) {
			int e = st[i];
			if (!visited[e]) {
				dfs(e, false);
				_count++;
			}
		}

		cout <<  _count-1 << endl;
	}
	return 0;
}