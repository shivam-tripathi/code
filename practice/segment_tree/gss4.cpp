// http://www.spoj.com/problems/GSS4/
// @author: Shivam Tripathi

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100001

long long tree[SIZE*4];
long long arr[SIZE];
int n;

long long query(int L, int R, int l=0, int r=n-1, int index=1) {
	
	if (L <= l &&  r<= R) {
		return tree[index];
	}


	int ones = r-l+1;

	/*
	if (tree[index] == ones) {
		r = min(R, r);
		l = max(L, l);
		return r-l+1;
	}
	*/

	int mid = (l+r) >> 1;
	int left = index << 1;
	int right =  left + 1;
	long long ans;

	if (R <= mid) {
		ans = query(L, R, l, mid, left);
	}
	else if (L > mid) {
		ans = query(L, R, mid+1, r, right);
	}
	else {	
		ans = query(L, R, l, mid, left) + query(L, R, mid+1, r, right);
	}

	return ans;
}

void update(int L, int R, int l=0, int r=n-1, int index=1) {	
	int ones = r-l+1;
	
	if (tree[index] <= ones) {
		return;
	}

	if (l == r) {
		tree[index] = (long long)sqrt(tree[index]);
		arr[l] = tree[index];
		return;
	}

	int mid = (l+r) >> 1;
	int left = index << 1;
	int right = left+1;

	if (R <= mid) {
		update (L, R, l, mid, left);
	}
	else if (L > mid) {
		update (L, R, mid+1, r, right);
	}
	else {
		update (L, 	R, 	l, mid, left);
		update (L, 	R, 	mid+1,  r, 	 right);
	}

	tree[index] = tree[left]+tree[right];
}

void build(int l=0, int r=n-1, int index=1) {
	if (l == r) {
		tree[index] = arr[l];
		return;
	}

	build(l, (l+r)/2, 2*index);
	build((l+r)/2+1, r, 2*index+1);

	tree[index] = tree[2*index] + tree[2*index+1];
}

void check(int l=0, int r=n-1, int index=1) {
	cout << l << " to " << r << " " << tree[index] << endl;
	
	if (l==r) {
		return;
	}

	int mid = (l+r) >> 1;
	check(l, mid, index<<1);
	check(mid+1, r, (index<<1)+1);
}

void linear() {
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(int argc, char const *argv[]){
	int c=0;
	
	
	while (scanf("%d", &n) != EOF) {
		printf("Case #%d:\n", ++c);

		for (int i=0; i<n; i++) {
			scanf("%lld", &arr[i]);
		}

		build();

		int q;
		scanf("%d", &q);

		while(q--) {
			int t, a, b;
			scanf("%d %d %d", &t, &a, &b);
			if (a > b) swap(a,b);

			if (t == 1) {
				long long res = query(a-1, b-1);
				printf("%lld\n", res);
			}
			if (t == 0) {
				update(a-1, b-1);
			}
		}
		printf("\n");
		
	}

	return 0;
}