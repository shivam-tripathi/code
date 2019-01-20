#include <bits/stdc++.h>
using namespace std;

const int size = 10+10;

int m, n;
bool visited[size];
vector<int> adj[size];


int main() {
	int t;
	cin >> t;
	while(t--) {
	    cin >> n >> m;
	    memset(visited, false, sizeof visited);
	    for(int i=0; i<n; i++) {
	        adj[i].clear();
	    }

	    for(int i=0; i<m; i++) {
	        int a, b;
	        cin >> a >> b;
	        adj[a-1].push_back(b-1);
	        adj[b-1].push_back(a-1);
	    }

	    bool ans = dfs(0);

	}
	return 0;
}