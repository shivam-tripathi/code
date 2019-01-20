#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

map <string, string> dict;

string encoded[10000+10];

int dp[10000];

int n;

struct Node {
	Node *nodes[2];
	Node() {
		node[0] = NULL;
		node[1] = NULL; 
	}
}

string encode(string temp) {
	static int index = 0;
	string encode_temp = "";
	for(int i=0; i<temp.size(); i++) {
		encode_temp += dict[temp[i]];
	}
	return encode_temp;
}

int solve (int index) {
	int ans = 0;
	int temp;
	for (int i = 0; i < n; i++) {

	}
}

int main(){
	dict[ 'A' ] = ".-";
	dict[ 'B' ] = "-...";
	dict[ 'C' ] = "-.-.";
	dict[ 'D' ] = "-..";
	dict[ 'E' ] = ".";
	dict[ 'F' ] = "..-.";
	dict[ 'G' ] = "--.";
	dict[ 'H' ] = "....";
	dict[ 'I' ] = "..";
	dict[ 'J' ] = ".---";
	dict[ 'K' ] = "-.-";
	dict[ 'L' ] = ".-..";
	dict[ 'M' ] = "--";
	dict[ 'N' ] = "-.";
	dict[ 'O' ] = "---";
	dict[ 'P' ] = ".--.";
	dict[ 'Q' ] = "--.-";
	dict[ 'R' ] = ".-.";
	dict[ 'S' ] = "...";
	dict[ 'T' ] = "-";
	dict[ 'U' ] = "..-";
	dict[ 'V' ] = "...-";
	dict[ 'W' ] = ".--";
	dict[ 'X' ] = "-..-";
	dict[ 'Y' ] = "-.--";
	dict[ 'Z' ] = "--..";

	int d;
	cin >> d;
	while (d--) {
		cin >> n;
		string temp;
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			temp = encode(temp);

		}
	}

    return 0;
}

