// Longest path in a tree
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<int> adj[10000+10];
bool visited[10000+10];

pii dfs(int src) {
	int l=0, r=0, ans=0;
	visited[src] = true;
	for(int i=0; i<adj[src].size(); i++) {
		if (visited[adj[src][i]])
			continue;
		pii tempp = dfs(adj[src][i]);
		int temp = tempp.second;
		if (temp > l) {
			r = l;
			l = temp;
		}
		else if (temp > r)
			r = temp;
		ans = max(ans, tempp.first);
	}
	return pii(max(l+r+1, ans), max(l,r)+1);
}

int main(int argc, char const *argv[]) {
	int n, a, b;
	ios::sync_with_stdio(false);
	cin >> n;
	n--;
	memset(visited, false, sizeof visited);
	while(n--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << dfs(1).first - 1 << endl;
	return 0;
}