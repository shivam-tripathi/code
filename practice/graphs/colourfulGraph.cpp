#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> adj[110];
int n, m;
int a, b, c;
bool visited[110];

bool dfs(int src, int c) {
	visited[src] = true;
	if (src == b) return true;

	for(int i=0; i<adj[src].size(); i++) {
		int node = adj[src][i].first;
		int color = adj[src][i].second;
		if (color == c && !visited[node]) {
			if (dfs(node, c)) return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(pii(b,c));
		adj[b].push_back(pii(a,c));
	}

	int q;
	cin >> q;
	int ans;
	while(q--) {
		cin >> a >> b;
		ans=0;
		set<int> colorset;
		for(int i=0; i<adj[a].size(); i++) {
			int color = adj[a][i].second;
			if(colorset.find(color) != colorset.end()) continue;
			memset(visited, false, sizeof visited);
			if (dfs(a, color)) ans++;
			colorset.insert(color);
		}
		cout << ans << endl;
	}
	return 0;
}