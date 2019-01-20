#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
set<pii> occurred;
int a, b, c;

struct State {
	int a;
	int b;
	int moves;
	State(int a, int b, int c):
		a(a),
		b(b),
		moves(c)
	{}
};

// class Cmp {
// 	bool operator() (const state a, const state b) {
// 		return a.moves < b.moves;
// 	}
// }

#define PRINT (cout << "Not in the set " << pq.back().a << " " << pq.back().b << endl)

int simulate() {
	// priority_queue<state, vector<state>, Cmp()> pq;
	queue<State> pq;
	occurred.insert(make_pair(0,0));
	pq.push(State(a, 0, 1));
	pq.push(State(0, b, 1));
	occurred.insert(make_pair(0,0));
	occurred.insert(make_pair(a,0));
	occurred.insert(make_pair(0,b));


	int ans = -1;
	while(!pq.empty()) {
		State temp = pq.front();
		pq.pop();
		int first = temp.a;
		int second = temp.b;
		int moves = temp.moves;

		// cout << first << " <--> " << second << " = " << moves << endl;

		if (first == c || second == c) {
			ans = moves;
			break;
		}

		// Empty moves
		if (occurred.find(make_pair(0, second)) == occurred.end()) {
			pq.push(State(0, second, moves+1));
			occurred.insert(make_pair(0,second));
			// PRINT;
		}

		if (occurred.find(make_pair(first, 0)) == occurred.end()) {
			pq.push(State(first, 0, moves+1));
			occurred.insert(make_pair(first,0));
			// PRINT;
		}

		// Fill moves
		if (occurred.find(make_pair(first, b)) == occurred.end()) {
			pq.push(State(first, b, moves+1));
			occurred.insert(make_pair(first,b));
			// PRINT;
		}

		if (occurred.find(make_pair(a, second)) == occurred.end()) {
			pq.push(State(a, second, moves+1));
			occurred.insert(make_pair(a,second));
			// PRINT;
		}

		// Transfer moves
		int filla = max(0, first-(b-second));
		int fillb = min(b, first+second);
		if(occurred.find(make_pair(filla, fillb)) == occurred.end()) {
			pq.push(State(filla, fillb, moves+1));
			occurred.insert(make_pair(filla,fillb));
			// PRINT;
		}

		fillb = max(0, second-(a-first));
		filla = min(a, first+second);
		if(occurred.find(make_pair(filla, fillb)) == occurred.end()) {
			pq.push(State(filla, fillb, moves+1));
			occurred.insert(make_pair(filla,fillb));
			// PRINT;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		occurred.clear();
		cin >> a >> b >> c;
		if (a<b) swap (a,b);

		if (c==0) {
			cout << 0 << endl;
			return 0;
		}
		cout << simulate() << endl;
	}
	return 0;
}