#include <bits/stdc++.h>
using namespace std;
 
#define SIZE 1000000+2
 
int seg_tree[4 * (100000+2)];
int sieve[SIZE];	
 
void build(int a[], int l, int r, int index=1){
	if(l>r)
		return;
	else if(l == r){
		seg_tree[index] = sieve[a[l]];
		return;
	}
 
	build(a, l, (l+r)/2, 2*index);
	build(a, (l+r)/2+1, r, 2*index+1);
 
	seg_tree[index] = max(seg_tree[2*index], seg_tree[2*index+1]);
	return;
}
 
int query(int l, int r, int ls, int rs, int index=1){
	if(rs < l || r < ls)
		return -1;
 
	if(l <= ls && rs <= r){
		return seg_tree[index];
	}
 
	int mid = (ls + rs) / 2;
 
	return max(query(l, r, ls, mid, index*2), query(l, r, mid+1, rs, index*2+1));
}
 
 
void update(int l, int r, int ls, int rs, int a[],  int index){
	if(l > rs || r < ls)
		return;
 
	if(ls == rs){
		a[ls] = a[ls]/sieve[a[ls]];
		seg_tree[index] = sieve[a[ls]];
		return;
	}
 
	if(seg_tree[index] == 1)
		return;
	if(seg_tree[index*2] != 1)
		update(l, r, ls, (ls+rs)/2, a, index*2);
	if(seg_tree[index*2+1] != 1)
		update(l, r, (ls+rs)/2+1, rs, a, index*2+1);
	
	seg_tree[index] = max(seg_tree[index*2], seg_tree[index*2+1]);
}
 
 
int main(){
	// Construct sieve
	sieve[1] = 1;
	for(int i=2; i<SIZE; i++){
		if(sieve[i] == 0){
			for(int j=i; j<SIZE; j+=i){
				if(sieve[j] == 0){
					sieve[j] = i;
				}
			}
		}
	}
 
	// Enter test cases
	int t; 
	scanf("%d", &t);
	// cin >> t;
 
	// Evaluate each test case
	while(t--){
		int n, m;
		cin >> n >> m;
		int a[n];
		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
			// cin >> a[i];
		}
 
		build(a, 0, n-1);
 
		int t, l, r;
		for(int i=0; i<m; i++){
			scanf("%d %d %d", &t, &l, &r);
			// cin >> t >> l >> r;
			if(t == 0){
				update(l-1, r-1, 0, n-1, a, 1);
			}
			if(t == 1){
				printf("%d ", query(l-1, r-1, 0, n-1));
				// cout << query(l-1, r-1, 0, n-1) << " ";
			}
		}
		printf("\n");
		// cout << endl;
	}
}