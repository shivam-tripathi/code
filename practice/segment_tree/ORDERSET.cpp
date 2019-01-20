#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int elements[inf]; 

void insert (int elem) {
	if (elem < 0 || elem > inf-10)
		return;

	elements[elem]++;
}

void del (int elem) {
	if (elem < 0 || elem > inf-10)
		return;

	elements[elem]--;
}


int main(){
	int q;
	scanf("%d", &q);
	while (q--) {
		char type;
		int arg;
		scanf("%c %d", &type, &arg);

		if (type == 'I') {
			insert(arg);
		}

		if (type == 'D') {
			del(arg);
		}
	}
    return 0;
}