#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int n;

struct Node {
	char el;
	Node *next[10];
	int below;
	bool isleaf;
	Node() {
		for(int i=0; i<10; i++)
			this->next[i] = NULL;
		below = 0;
		isleaf = false;
	}
};

Node *root;

bool insert(string a) {
	int index = 0;
	Node *node = root;
	char c;
	// cout << "Inserting ";
	while(true) {
		node->below++;
		
		c = a[index];
		// cout << c-'0' << " ";
		
		if(node->next[c-'0'] == NULL) {
			node->next[c-'0'] = new Node();
		}

		index++;
		node = node->next[c-'0'];

		if (index < a.size() && node->isleaf) {
			return true;
		}

		if (index == a.size()) {
			node->isleaf = true;
			if (node->below != 0) {
				return true;
			}
			else return false;
		}
	}
}

int main(){
 	int t;
 	cin >> t;
 	while (t--) {
 		cin >> n;
 		root = new Node();
 		string a;
 		bool hasPrefix = false;
 		while (n--) {
 			cin >> a;

 			if (hasPrefix != true) {
	 			if (insert(a)) {
	 				hasPrefix = true;
	 				// cout << "Found it" << endl;
	 			}
 			}

 			// cout << endl;
 		}

 		if (hasPrefix) {
 			cout << "NO" << endl;
 		} else {
 			cout << "YES" << endl;
 		}
 	}   
    return 0;
}