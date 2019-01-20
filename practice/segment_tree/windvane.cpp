#include <bits/stdc++.h>
using namespace std;

int n, m;
int mat[1010*1010];
int tree[4*1010*1010];


int index(int x, int y) {
	cout << "Updating index " << n*x + y << endl;
	return n*x + y;
}

int direc(char x) {
	return (x == 'N') ? 0 : ((x == 'E') ? 1 : ((x == 'W') ? 2 : 3));
}

char rev_direc(int x) {
	return (x == 0) ? 'N' : ((x == 1) ? 'E' : ((x == 2) ? 'W' : 'S'));
}


void build(int l=0, int r=(n*m-1), int index = 0) {
	if (l>r) return;
	if (l == r) {
		tree[l] = mat[index];
		return;
	}

	int left_child = 2*index + 1;
	int right_child = 2*index + 2;
	build(l, (l+r)/2, 2*index + 1);
	build((l+r)/2+1, r, 2*index + 2);


	if (tree[left_child] == tree[right_child]) tree[index] = tree[left_child];
	else tree[index] = -1;

}

void update(int l, int r, int d, int L=0, int R=(n*m-1), int index = 0) {
	if (l > R || r < L) return;

	if (L <= l && r <= R && tree[index] != -1) {
		int temp = tree[index];
		tree[index] = (tree[index]+d)%4;
		cout << " || Changed to " << rev_direc(temp) << " to " << rev_direc(tree[index]) << endl;
		return;
	}

	int mid_index = (L+R)/2;
	int left_child = 2*index + 1;
	int right_child = 2*index + 2;
	if (l <= mid_index) update(l, r, d, L, mid_index, left_child);
	else update(l, r, d, mid_index+1, right_child);
}


int query(int l, int r, int L=0, int R=(n*m-1), int index=0) {
	if (l > R || r < L) return 0;

	if (L <= l && r <= R && tree[index] != -1) {
		return tree[index];
	}

	int mid_index = (L+R)/2;
	int left_child = 2*index + 1;
	int right_child = 2*index + 2;
	if (l <= mid_index) return query(l, r, L, mid_index, left_child);
	else return query(l, r, mid_index+1, right_child);
}



int main(int argc, char const *argv[])
{
	cin >> n >> m;
	int x, y, q, d;
	char c;
	string s;


	for(int i=0; i<n; i++) {
		cin >> s;
		for(int j=0; j<m; j++) {
			cout << s[j] << " mapped to " << direc(s[j]) << " | ";
			mat[index(i, j)] = direc(s[j]);
		}
	}

	memset(tree, 0, sizeof tree);
	build();

	cout << "Beginning run " << endl;

	cin >> q;
	int x1, y1, x2, y2;
	while(q--) {
		cin >> c >> x1 >> x2;
		if (c == 'D') {
			cout << "Query ";
			cout << rev_direc(query(index(x1, y1), index(x1, y1))) << endl;
			continue;
		}
		cin >> x2 >> y2 >> d;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		if (d == 1) d = -1;
		if (d == 0) d = 1;

		x1--; x2--; y1--; y2--;
		for(int i=x1; i<x2; i++) {
			cout << "flip by " << d << " | ";
			update(index(i, y1), index(i, y2), d);
		}
	}
	return 0;
}