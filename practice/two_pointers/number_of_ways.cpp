// http://codeforces.com/problemset/problem/466/C

#include <iostream>
using namespace std;

int main(){
	int n, sum = 0, count = 0;
	cin >> n;
	int a[n], s_l[n], s_r[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		sum += a[i];
		s_l[i] = sum;
	}
	sum = 0;
	for (int i = n-1; i > 0; --i){
		sum += a[i];
		s_r[i] = sum;
	}
	int l = 0, r = n-1;
	while(l < r){
		if(s_l[l] < s_r[r])
			l++;
		else if(s_l[l] > s_r[r])
			r--;
		else {
			if(s_l[l] == s_l[r-1])
				count++;
			int temp=r-1;
			while(s_l[l] == 2*s_l[temp-1]){
				temp--;
				count++;
			}
			temp = l+1;
			while(s_l[temp] == s_r[r-1]){
				temp++;
				count++;
			}
			l++;
			r--;
		}
	}
	cout << count << endl;
}