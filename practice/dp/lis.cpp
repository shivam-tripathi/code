/*LIS for strictly increasing subsequence*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int r, l;

// Find the sequence with just smaller element than the given sequence 
int find(ll a[], int elem){
	int mid;
	l = 0; 
	r = n-1;
	while(l <= r){		

		mid = (l+r)/2;

		if(a[mid] == elem)
			break;

		else if(a[mid] > elem)
			r = mid-1;

		else 
			l = mid+1;
	}
	if(a[mid] == elem || a[mid] > elem) 
		return mid - 1;

	return mid;
}



int main(int argc, char const *argv[]){
	scanf("%lld", &n);

	ll elem[n];
	for(int i=0; i<n; i++){
		scanf("%lld", &elem[i]);
	}

	ll a[n];

	for(int i=0; i<n; i++){
		a[i] = INT_MAX;
	}

	for(int i=0; i<n; i++){
		int index = find(a, elem[i]);
		if(index == -1){
			a[index+1] = elem[i];
			r = 0;
		}
		else{
			if((elem[i]) < a[index+1]){
				a[index+1] = elem[i];
				r = max(r, index+1);
			}
		}
	}

	cout << r+1 << endl;

	return 0;
}
