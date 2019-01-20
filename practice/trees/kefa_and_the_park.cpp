// http://codeforces.com/problemset/problem/580/C

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<int> adj[100010];
bool visited[100010];
int cats[100010];
int n, m;

int bfs() {
	queue<pii> nodes;
	nodes.push(make_pair(1, cats[1]));
	visited[1] = true;
	int c = 0;

	while(!nodes.empty()) {
		pii node = nodes.front();
		nodes.pop();
		int index = node.first;
		int cat = node.second;

		if (cat > m)
			continue;

		int k = 0;
		for(int i=0; i<adj[index].size(); i++) {
			int point = adj[index][i];
			if (!visited[point]) {
				k++;
				int push_cats = cats[point] == 1 ? cat + 1 : 0;
				if (push_cats > m)
					continue;
				visited[point] = true;
				nodes.push(make_pair(point, push_cats));
			}
		}
		if (k==0) {
			// cout << index << " " << cat << endl;
			c++;
		}
	}
	return c;
}

void print() {
	for(int i=1; i<=n; i++) {
		cout << i << " : ";
		for(int j=0; j<adj[i].size(); j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> cats[i];
	}

	int a, b;
	for(int i=0; i<n-1; i++) {
		cin >> a >> b;
		// cout << a << " <--> " << b << endl;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// print();

	cout << bfs() << endl;

	return 0;
}