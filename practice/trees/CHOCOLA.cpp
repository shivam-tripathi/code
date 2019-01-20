#include <bits/stdc++.h>
using namespace std;

int m, n;
int cost[2010];

struct node {
	int r, c;
	bool *visited;
	node(int size) {
		r = c = 1;
		visited = new bool[size];
	}
};

long long _ans;

long long solve(node *root) {
	long long ans = LLONG_MAX, temp;

	// if (root->r == m || root->c == n) return 0;

	for(int i=0; i<(m+n); i++) {

		if (root->visited[i]) continue;

		if (i < m) {
			root->r++;
			root->r = min(m+1, root->r);
			temp = cost[i] * (root->c);
		}
		else {
			root->c++;
			root->c = min(n+1, root->c);
			temp = cost[i] * (root->r);
		}
		// if (temp == 0) cout << "ZERO!!! " << cost[i] << " * " <<  root->r << " " << root->c << endl;
		root->visited[i] = true;

		long long check = solve(root);

		// if (depth == 1)
			// cout << "\t>>" << temp << " + " << check << endl;
		ans = min(ans, temp+check);

		// if (depth == 0)
		// 	_ans = ans;

		// Reset all values
		root->visited[i] = false;
		if (i < m) {
			root->r--;
			root->r = max(root->r, 1);
		}
		else {
			root->c--;
			root->c = max(1, root->c);
		}

		// if (depth == 0)
		// 	cout << temp << " " << ans << endl;
		// if (depth == 1)
		// 	cout << "\t temp " << temp << " ans " << ans << endl;
		// if (depth == 6 || depth == 8)
		// 	cout << "\t\t temp " << temp << " ans " << ans << endl;
	}
	if (ans == LLONG_MAX) return 0;
	return ans;
}

long long solution() {
	priority_queue<int, vector<int>, std::less<int> > row;
	priority_queue<int, vector<int>, std::less<int> > col;
	for(int i=0; i<m; i++) {
		row.push(cost[i]);
	}
	for(int i=m; i<(m+n); i++) {
		col.push(cost[i]);
	}

	bool flag = false;
	long long ans = 0;
	int r=1, c=1;
	while(!row.empty() && !col.empty()) {
		int er = row.top();
		int ec = col.top();
		int temp1, temp2;
		if (r != m) temp1 = (er*c + ec*(r+1));
		else temp1 = (er*c + ec*m);
		if (c != n) temp2 = (ec*r + er*(c+1));
		else temp2 = (ec*r + er*n);

		if (temp1 < temp2) {
			r++;
			ans += (er*c);
			row.pop();
			flag = true;
		}
		else if (temp1 > temp2) {
			c++;
			ans += (ec*r);
			col.pop();
			flag = false;
		}
		else {
			if (row.size() > col.size()) {
				r++;
				ans += er*c;
				row.pop();
				flag = true;
			}
			else {
				c++;
				ans += (ec*r);
				col.pop();
				flag = false;
			}
		}
	}
	while (!row.empty()) {
		ans += row.top() * c;
		row.pop();

	}
	while (!col.empty()) {
		ans += (col.top() * r);
		col.pop();
	}
	return ans;
}


int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		m--;
		n--;
		for(int i=0; i<m+n; i++) {
			cin >> cost[i];
		}

		// node start(m+n);
		// cout << solve(&start) << endl;
		cout << solution() << endl;
	}
	return 0;
}