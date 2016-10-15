#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--){
		int o=0, z=0;
		string a;
		cin >> a;
		for(int i=0; i<a.length(); i++){
			if(a[i] == '0')
				z++;
			else o++;
		}
		if(z == 1 | o == 1)
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
	return 0;
}