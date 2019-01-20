// http://codeforces.com/problemset/problem/20/C
#include <bits/stdc++.h>
using namespace std;

const int size = 1e5 + 100;
typedef pair<int, int> pii;
vector<pii> adj[size];
bool visited[size];
int _distance[size];
int parent[size];
int n, m;

struct Cmp {
	bool operator() (const pii &a, const pii &b) {
		return a.second > b.second;
	}
};

void dijkstra(int src) {
	priority_queue<pii, vector<pii>, Cmp> pq;
	pq.push(make_pair(src, 0));

	for(int i=1; i<=n; i++) { _distance[i] = INT_MAX; parent[i] = i; visited[i] = false;}

	int processed=0;
	while(!pq.empty() ) {
		pii temp = pq.top();
		pq.pop();
		int node = temp.first;
		int dist = temp.second;
		visited[node] = true;
		_distance[node] = dist;

		for(int i=0; i<adj[node].size(); i++) {
			int next = adj[node][i].first;
			int weight = adj[node][i].second;
			if (!visited[next] && (dist + weight) < _distance[next]) {
				_distance[next] = dist+weight;
				parent[next] = node;
				pq.push(make_pair(next, _distance[next]));
			}
		}
	}

	vector<int> ans;
	while(parent[n] != n) {
		ans.push_back(n);
		n = parent[n];
	}
	ans.push_back(n);

	if (ans.size() == 1) cout << -1;
	else {
		for(int i=ans.size()-1; i>=0; i--) {
			cout << ans[i] << " ";
		}
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	int x, y, w;

	for(int i=0; i<m; i++) {
		cin >> x >> y >> w;
		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, w));
	}

	dijkstra(1);

	return 0;
}