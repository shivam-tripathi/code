#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pairs;
typedef long long ll;
ll seg_tree[4*100000];

list<int>* adj;
list<pairs>* tickets;
ll* cost;
int n;


void update(int l, ll val, int ls = 0, int rs = n-1, int index=1){
	if(ls == rs){
		seg_tree[index] = val;
		return;
	}
	else{
		int mid = (ls + rs)/2;
		if(l <= mid)
			update(l, val, ls, mid, 2*index);
		else 
			update(l, val, mid+1, rs, 2*index+1);
		seg_tree[index]  = min(seg_tree[2*index], seg_tree[2*index+1]);
	}
}

ll query(int l, int r, int ls, int rs, int index=1){
	if(r < ls || rs < l)
		return 1e18;

	if(l <= ls && rs <= r)
		return seg_tree[index];

	return( min ( query(l, r, ls, (ls+rs)/2, 2*index), query(l, r, (ls+rs)/2+1, rs, 2*index+1) ) );
}

void build(int src=0, int depth=1, int p=-1){

	list<int>::iterator i;
	list<pairs>::iterator t;

	for(i = adj[src].begin(); i != adj[src].end(); i++){
		if ((*i) == p)
			continue;
		if(!tickets[*i].empty()){
			for(t = tickets[*i].begin(); t != tickets[*i].end(); t++){
				int need_depth = max(0, depth-((*t).first));
				cost[*i] = min(cost[*i], (*t).second + query(need_depth, depth-1, 0, n-1));
			}
		}

		update(depth, cost[*i]);
		build(*i, depth+1, src);
		update(depth, LONG_MAX);
	}
}

int main(int argc, char const *argv[]){
	int m, c1, c2, t1, t2, t3;
	scanf("%d %d", &n, &m);

	adj = new list<int>[n+10];
	tickets = new list<pairs>[n + 10];
	cost = new ll[n+10];
	for(int i=0; i<n; i++)
		cost[i] = 1e18;
	
	for(int i=0; i<n-1; i++){
		scanf("%d %d", &c1, &c2);
		adj[c2-1].push_back(c1-1);
		adj[c1-1].push_back(c2-1);
	}
	
	/*depth and cost*/

	for(int i=0; i<m; i++){
		scanf("%d %d %d", &t1, &t2 , &t3);
		tickets[t1-1].push_back(pairs(t2, t3));
	}

	// update(0, 0, 0, n-1, 0);

	build();

	int q, h;
	scanf("%d", &q);
	for(int i=0; i<q; i++){
		scanf("%d", &h);
		printf("%lld\n", cost[h-1]);
	}
	return 0;
}