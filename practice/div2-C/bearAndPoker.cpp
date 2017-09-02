#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	int arr[t];
	for(int i=0; i<t; i++) {
		cin >> arr[i];
		while(arr[i]%2==0) arr[i] /= 2;
		while(arr[i]%3==0) arr[i] /= 3;
	}
	for(int i=1; i<t; i++) {
		if (arr[i] != arr[0]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}