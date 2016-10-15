#include <iostream>
#include <algorithm>
using namespace std;

bool check_possible(int arr[], int size, int k, int c){
	int i = 0;
	// cout << "checking " << k << " " << c-1 << endl;
	while( i < size && c > 0){
		c--;
		// cout << "k = " << k << " value " << arr[i] << " left " << c << endl;
		int past = i++;
		while((arr[i] - arr[past]) < k) {
			i++ ;
		}
	}
	if(c > 0) return false;
	return true;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, c;
		cin >> n >> c;
		
		int arr[n];
		int size = n;

		for(int i=0; i<size; i++){
			cin >> arr[i];
		}

		sort(arr, arr+size-1);

		// for(int i=0; i<size; i++){
		// 	cout <<  arr[i] << " ";
		// }
		// cout << endl;

		int lower = 0, upper = arr[size-1], mid = (lower+upper)/2, ans = 0;

		while(lower <= upper){
			if(check_possible(arr, size, mid, c)){
				ans = max(ans, mid);
				lower = mid+1;
				mid = (upper+lower)/2;
			}
			else{
				upper = mid-1;
				mid = (upper+lower)/2;
			}
		}

		cout << ans << endl;
	}
}