#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 32;
	/*for(int j=1; (1<<j) <= n; j++) {
		for(int i=0; (i + (1<<j)) < n; i++) {
			// cout << ">" << (i + (1<<j)) << " " << n << " " <<  ((i + (1<<j)) < n )<< endl;
			// i++;
			// cout << ">" << (i + (1<<j)) << " " << n << " " <<  ((i + (1<<j)) < n )<< endl;
			// i--;
			cout << i << " " << j << endl;
		}
	}*/

	int i=0, j=1;
	while((1<<j) <= n) {
		i=0;
		while((i+(1<<j )) < n) {
			cout << i << " " << j << endl;
			i++;
		}
		j++;
	}
	return 0;
}