#include <bits/stdc++.h>
using namespace std;

bool checker(int arr[], int k, int f, int size){
	int i = 0;
	while(i < size && f>0){
		f -= arr[i]/k;
		i++;
	}
	if(f > 0) return false;
	else return true;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, f;
		cin >> n >> f;
		int arr[n], temp=-1;
		for (int i = 0; i < n; ++i){
			cin >> arr[i];
			temp = max(temp, arr[i]);
		}

		int low = 0, high = temp;

		while(low < high){
			int mid = (low+high+1)/2;
			if(checker(arr, mid, f, n)){
				low = mid;
			}
			else{
				high = mid-1;
			}
		}
		cout << low << endl;
	}
}