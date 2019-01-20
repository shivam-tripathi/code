// http://codeforces.com/problemset/problem/659/C

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, count;
	cin >> n >> count;

	int arr[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);

	vector<int> ans;
	int iter = 1, track=0;
	const int size = 1e9;
	while(iter < size && (count - iter >= 0)) {
		if (track < n && iter == arr[track]) {
			track ++;
			iter ++;
			continue;
		}

		count = count - iter;
		ans.push_back(iter);
		iter++;
	}

	cout << ans.size() << endl;
	for(int i; i<ans.size(); i++) cout << ans[i]  << " ";
	cout << endl;

	return 0;
}