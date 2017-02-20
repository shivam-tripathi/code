#include <bits/stdc++.h>
using namespace std;

int n, m;
int V[1000+10];

int cost[1000+10];

list<int> M[1000+10];

int minimum() {
	int index = 0, min_val = V[0], ind_cost=V[0];
	for(int i=1; i<n; i++) {
		if(V[i] > min_val) {
			index = i;
			min_val = V[i];
		}
	}
	return index;
}

void fix(int k) {
	list<int> :: iterator i;
	for(i=M[k].begin(); i != M[k].end(); i++) {
		cost[*i] -= V[k];
	}
}

void state(){
	for(int i=0; i<n; i++) {
		cout << i << ": " << cost[i] << endl;
	}
}

int main(int argc, char const *argv[]){
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> V[i];

	int a, b;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		a--;
		b--;
		M[a].push_back(b);
		M[b].push_back(a);
		cost[a] += V[b];
		cost[b] += V[a];
	}

	int rem = n, least, ans = 0;
	// state();
	// cout << endl;

	while(rem--) {
		least = minimum();
		ans += cost[least];
		fix(least);
		cost[least] = INT_MAX;
		V[least] = -1;
		// state();
		// cout << endl;
	}

	cout << ans << endl;
	return 0;
}


/*
Nothing else from greedy comes to mind. It is essentially greedy problem. Having that sorted, we
now decide in what way is this greedy.
There are two ways to look at this - every node has to be removed and every edge has to be removed
essentially.
If we go by approach that every node has to be removed - then we choose node with minimum cost and
remove it.
If we go by the approach that every edge has to be removed - then we choose the node with the
maximum *value* and then remove it - as on either one the edge will contribute to the edge removal
depending on which is chosen. So it's better to remove the one with larger value, as it will reduce
the cost.
Now the second method definitely feels better. We now have to contradict the first one.
We see that there is a pattern to the removal of nodes. If we can in some way can manage to change
this pattern we can contradict.
*/