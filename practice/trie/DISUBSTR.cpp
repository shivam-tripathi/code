#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main(int argc, char const *argv[])
{	int t;
	cin >> t;
	string s;
	unordered_set<string> uset;

	while(t--) {
		cin >> s;
		int n = s.size();
		uset.clear();
		for(int i=1; i<=n; i++) {
			for(int j=0; j+i<=n; j++) {
				string w = s.substr(j, i);
				uset.insert(w);
			}
		}

		cout << uset.size() << endl;
	}

	return 0;
}