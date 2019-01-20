// http://codeforces.com/problemset/problem/115/A

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2000+10];
vector<int> root;

typedef pair<int, int> pii;

int main(int argc, char const *argv[])
{
	int n, a, b;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> b;
		if (b == -1) root.push_back(i);
		else {
			adj[b-1].push_back(i);
		}
	}

	int max_depth = 1;
	queue<pii> q;
	for(int i=0; i<root.size(); i++) {
		q.push(make_pair(root[i], 1));
		bool visited[2000+10];
		memset(visited, false, sizeof visited);
		visited[root[i]] = true;
		while(!q.empty()) {
			pii src = q.front();
			q.pop();
			int node = src.first;
			int depth = src.second;
			// cout << node << " at " << depth << endl;
			max_depth = max(max_depth, depth);
			for(int i=0; i<adj[node].size(); i++) {
				if (!visited[adj[node][i]]) {
					visited[adj[node][i]] = true;
					q.push(make_pair(adj[node][i], depth+1));
				}
			}
		}
	}
	cout << max_depth << endl;
	return 0;
}