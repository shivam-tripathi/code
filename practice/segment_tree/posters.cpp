#include <bits/stdc++.h>
using namespace std;

#define SIZE 40000

struct _posters {
	int start;
	int end;
}posters[SIZE + 2];

int n;

map<int, int> mapped;

int positions[80000+10];

int cmp (const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

struct _node {
	int color;
	bool prop;
} tree[SIZE*3];

int last;

void insert (int color, int left, int right, int L=1, int R=last, int index=1) {
	if (right < L || left > R)
		return;
	if (left <= L && right >= R) {
		tree[index].color = color;
		tree[index].prop = true;
		return;
	}

	if (tree[index].color != 0 && tree[index].prop) {
		tree[2*index].color = tree[2*index+1].color = tree[index].color;
		tree[2*index].prop = tree[2*index+1].prop = true;
		tree[index].color = 0;
		tree[index].prop = false;
	}

	insert (color, left, right, L, (L+R)/2, 2*index);
	insert (color, left, right, (L+R)/2+1, R, 2*index+1);
}

int query (int pos, int L=1, int R=last, int index=1) {
	if (L == R) {
		return tree[index].color;
	}
	if (pos >= L && pos <= R && tree[index].color != 0) {
		return tree[index].color;
	}

	if (pos > (L+R)/2)
		return query (pos, (L+R)/2+1, R, 2*index+1);
	else
		return query (pos, L, (L+R)/2, 2*index);
}

set<int> _set;

int main (int argc, char const *argv[])
{
	int t;
	scanf ("%d", &t);
	n = 1;
	while (t--) {
		memset (posters, 0, sizeof(_posters) * n);
		memset (positions, 0, sizeof(int) * 2 * n);
		memset (tree, 0, sizeof(_node) * 3 * n);
		mapped.clear ();

		scanf ("%d", &n);
		for (int i=0; i<n; i++) {
			scanf ("%d %d", &posters[i].start, &posters[i].end);
			positions[2*i] = posters[i].start;
			positions[2*i+1] = posters[i].end;
		}
		qsort (positions, 2*n, sizeof(int), cmp);

		int map_index = 1;
		for (int i=0; i<2*n; i++) {
			if(mapped.count (positions[i]) == 0)
				mapped[positions[i]] = map_index++;
		}
		last = map_index-1;

		for (int i=0; i<n; i++) {
			insert (i+1, mapped[posters[i].start], mapped[posters[i].end]);
		}

		int temp;
		_set.clear();
		for (int i=0; i<last; i++) {
			temp = query (i+1);
			if(temp != 0) _set.insert(temp);
		}
		cout << _set.size() << endl;
	}
	return 0;
}
