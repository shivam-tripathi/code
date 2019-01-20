#include <bits/stdc++.h>
using namespace std;

const int SIZE = (int)1e5+100;

struct node {
	int squares;
	int linear;
	int count;
	bool lazy;
	node(int s, int l, int c) :
	squares(s), linear(l), count(c), flag(false)
	{}
};

int arr[SIZE];
node tree[4*SIZE];
int n;

void update(int L, int R, int l=0, int r=n-1, int index=1) {

}

int query(int L, int R, int l=0, int r=n-1, int index=1) {
	if (R < l || r < L) return 0;

	if (L < l && r < R) {
		if (tree[index].lazy) {
			tree[index].squares = tree[index].squares + 2*(tree[index].linear) + tree[index].count;
			tree[index].linear = tree[index].linear + tree[index].count;
			tree[index].lazy = false;

			int left = 2*index;
			int right = 2*index+1;

			tree[left].lazy = true;
			tree[right].lazy = true;
		}
		return tree[index].squares;
	}


	int left = 2*index;
	int right = 2*index + 1;

	return query(L, R, l, mid, left) + query(L, R, mid+1, r, right);
}

void build(int l, int r, int index=1) {
	if (l == r) {
		tree[index] = node(arr[l] * arr[l], arr[l], 1);
	}

	int left = 2*index;
	int right = 2*index+1;
	int mid = (l+r)/2;

	build(l, mid, left);
	build(mid+1, r, right);

	tree[index] = node (
					tree[right].squares + tree[left].squares,
					tree[right].linear + tree[left].linear,
					tree[right].count + tree[left].count);
}

int main(int argc, char const *argv[]) {

	return 0;
}