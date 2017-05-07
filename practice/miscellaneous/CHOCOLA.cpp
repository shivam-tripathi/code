#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	char type;
	Node (int val, int type) {
		this->val = val;
		this->type = type;
	}
};

Node *elements[2020];
int col[1010];
int m, n, r, c;

struct _Cmp {
    bool operator()(const Node *a, const Node *b) const
    {   
        return b->val < a->val;
    }   
} Cmp;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		r = c = 1;
		int temp;
		
		cin >> m >> n;
		m -= 1;
		n -= 1;

		for(int i = 0; i < m; i++) {
			cin >> temp;
			elements[i] = new Node(temp, 'r');
		}

		for (int i = m; i < m+n; ++i){
			cin >> temp;
			elements[i] = new Node(temp, 'c'); 
		}

		sort(elements, elements + m + n, Cmp);

		int index = 0, cost = 0;

		while (index < (m + n)) {
			if (elements[index]->type == 'r') {
				cost += c * elements[index]->val;
				r++;
			} else {
				cost += r * elements[index]->val;
				c++;
			}
			index++;
		}
		cout << cost << endl;
	}
	return 0;
}