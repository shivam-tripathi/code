#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

int main(){
    string bin;
    cin >> bin;
    string gray = "";
    gray += bin[0];
    for(int i=0; i<bin.length()-1; i++){
    	if(bin[i] == '0')
    		gray += bin[i+1];
    	else 
  			if(bin[i+1] == '1')
  				gray += '0';
  			else 
  				gray += '1';
    }
    cout << gray << endl;
    return 0;
}