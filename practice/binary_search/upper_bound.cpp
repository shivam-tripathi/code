#include <bits/stdc++.h>
using namespace std;

int upper(vector<int> a, int x){
	int low = 0, high = a.size()-1;
	int mid;
	while (high-low>1){
		mid = low + (high-low)/2;
		cout << "a[" << low << "] = " << a[low] << " | " << "a[" << mid << "] = " << a[mid] << " | " << "a[" << high << "] = " << a[high] << " | " << endl;
		if (x < a[mid])
			high = mid;
		else if (a[mid] <= x) {
			low = mid;
		}
	}
	mid = low + (high-low)/2;
	cout << "a[" << low << "] = " << a[low] << " | " << "a[" << mid << "] = " << a[mid] << " | " << "a[" << high << "] = " << a[high] << " | " << endl;
	return high;
}

int main() {
	srand(time(NULL));
	std::vector<int> v;
	for (int i=0; i<20; i++) {
		v.push_back((int)(100.0 * rand()/INT_MAX));
	}
	
	sort(v.begin(), v.end());
	for(int i; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	int x;
	while(true) {
		cout << "In: ";
		cin >> x;
		cout << "Out: " << v[upper(v, x)] << endl;
	}
}