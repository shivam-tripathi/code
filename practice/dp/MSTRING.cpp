#include <bits/stdc++.h>
using namespace std;

int dp[1000+10][1000+10];
int lvoki;
int ltoki;
string voki;
string toki;

int check(char ch, int itoki) {
	for(int i=itoki; i<ltoki; i++)
		if (ch == toki[i])
			return i;
	return -1;
}

int solve(int itoki=0 , int ivoki=0) {
	int index = check(voki[ivoki], itoki);

	if (index == -1)
		return 1;

	if (dp[ivoki][itoki])
		return dp[ivoki][itoki];

	if(ivoki+1 >= lvoki) {
		return 1;
	}

	int case1 = 1 + solve(index+1, ivoki+1);
	int case2 = solve(itoki, ivoki+1);

	dp[ivoki][itoki] = min (case1, case2);

	cout << " dp [" << ivoki << ", " << itoki << "] = " <<  dp[ivoki][itoki] << endl;

	return dp[ivoki][itoki];
}

int main(int argc, char const *argv[]){
	cin >> voki;
	cin >> toki;

	lvoki = voki.length();
	ltoki = toki.length();

	cout << solve() << endl;

	return 0;
}