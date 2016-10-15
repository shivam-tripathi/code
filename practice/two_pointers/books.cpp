#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
	int n, t;
	cin >> n >> t;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int l=0, r=0, sum=t, size=n, count=0, tsum=0;
	while(l<size){
		if(l!=0)
			tsum -= arr[l-1];
		while((tsum+arr[r]) <= sum && r<n){
			tsum += arr[r];
			r++;
		}
		if (count < r-l){
			count = r-l;
		}
		if(r==n)
			break;
		l++;
	}
	cout << count << endl;
	return 0;
}