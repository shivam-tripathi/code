#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int gcd(int a, int b){
	if(b == 0) return a;
	gcd(b, a%b);
}

int main(){
    cout << gcd(10, 15) << endl;
    cout << gcd(35, 10) << endl;
    cout << gcd(31, 2) << endl;
    return 0;
}