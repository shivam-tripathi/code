#include <bits/stdc++.h>
using namespace std;

const int size = (int)1e6+10;

vector<int> xarr;
vector<int> arr;
vector <char> option;
int bit[size];


// Coordinate compression 
// Number of queries is equal to 2*1^5 - all Insert queries can be mapped into an array of size < 1e6

void update(int idx, int val) {
	while(idx < arr.size()) {
		bit[idx] = max(0, bit[idx] + val);
		idx += (idx & (-idx));
	}
}

int count(int idx) {
	int sum = 0;
	while(idx > 0 && idx < arr.size()) {
		sum += bit[idx];
		idx -= (idx & (-idx));
	}
	return sum;
}

int idx_of_particular_cumulative_frequency(int freq) {

}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	int q;
	char c;
	int temp;
	cin >> q;
	
	// For coordinate compression you need all the values before hand 
	arr.push_back(0); 
	while(q--) {
		cin >> c >> temp;
		
		if (c == 'I')  arr.push_back(temp); 
	
		option.push_back(c);
		xarr.push_back(temp);
	}

	sort(arr.begin(), arr.end());


    // Remove redundant elements, ptr will be the final index of the array arr
    // First element is dummy value of zero, so default size is 1. 
	int ptr = (arr.size() > 1 ? 1 : 0);
	if (arr.size() > 2) {
		ptr=2, prev = arr[0];
		for(int i=2; i<arr.size(); i++) {
			if (arr[i] != prev) {
				prev = arr[i];
				arr[ptr++] = prev;
			}
		}	
	}

	for (int i=0; i<option.size(); i++) {
		char c = option[i];
		int x = xarr[i];
		if (c == 'I' || c == 'D') {
			int idx = binary_search(arr, arr+ptr, x);
			(c == 'I' ? c == 'D' ? update(idx, 1) : update (idx, -1));
		}
		if (c == 'C') {
			int idx = binary_search(arr, arr+ptr, x);
			printf("%d\n", count(idx-1));
		}
		if (c == 'K') {
			printf("%d\n", );
		}
	}
	return 0;
}