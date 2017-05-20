#include <bits/stdc++.h>
using namespace std;

int lower(vector<int> a, int x) {
	int low = 0, high = a.size()-1;
	int mid;
	while(high-low>1) {
		mid = low + (high - low)/2;
		cout << "a[" << low << "] = " << a[low] << " | " << "a[" << mid << "] = " << a[mid] << " | " << "a[" << high << "] = " << a[high] << " | " << endl;
		if (a[mid] >= x)
			high = mid;
		else 
			low = mid;
	}
	mid = low + (high - low)/2;
	cout << "a[" << low << "] = " << a[low] << " | " << "a[" << mid << "] = " << a[mid] << " | " << "a[" << high << "] = " << a[high] << " | " << endl;
	return low;
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	srand(time(NULL));
	for (int i=0; i<25; i++) {
		v.emplace_back((int)(100.0*rand()/INT_MAX));
	}
	sort(v.begin(), v.end());
	for (auto i : v) cout << i << " ";
		cout << endl;
	int x;
	while (x!=-1) {
		cout << "In :";
		cin >> x;
		cout << "Out :" << v[lower(v, x)] << endl;
	}
	return 0;
}