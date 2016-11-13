#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

/*
	Try to solve the modular equation first by comparison and then set the equals equation. 
	Or memorize the standard and get speedy results.
*/

// Trying to keep smaller value in a
void gcdUtil(int a, int b, int &x, int &y){
	if(a == 0){
		x = 0;
		y = 1; 
		return;
	}
	int x1, y1; 
	gcdUtil(b%a, a, x1, y1);
	x = y1 - (b/a)*x1;
	y = x1;
}

// Trying to keep larger value in a
void _gcdUtil(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return;
	}
	int x1, y1;
	_gcdUtil(b, a%b, x1, y1);
	y = x1 - (a/b)*y1;
	x = y1;
}

int gcd(int a, int b){
	int x, y;
	_gcdUtil(a, b, x, y);
	// cout << x << " " << y << endl;
	return (a*x)+(b*y);
}

int main(){
    cout << gcd(10, 15) << endl;
    cout << gcd(35, 10) << endl;
    cout << gcd(31, 2) << endl;
    return 0;
}