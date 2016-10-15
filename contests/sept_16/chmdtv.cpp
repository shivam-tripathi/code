#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, p;
int *pointers;

int check(ll a[], ll t){
	ll sum = 0, c=0;
	for(int i=0; i<n; i++){
		sum += a[i];
		if(sum >= t){
			sum = 0;
			pointers[c] = i+1;
			c++;
		}
	}
	if(c <= p){
		return -1;
	}
	if(c == p+1)
		return 0;
	if(c > p+1)
		return 1;
}

int main(int argc, char const *argv[]){
	scanf("%d %d", &n, &p);
	
	ll row[n], crow=0;
	ll column[n], clow=0;
	ll** a = new ll*[n];
	for(int i=0; i<n; i++)
		a[i] = new ll[n];
	ll sum = 0;

	p -= 1; 
	pointers = new int[n];


	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
			sum += a[i][j];
		}
		row[i] = sum;
		crow += sum;
		sum = 0;
	}

	sum = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			sum += a[j][i];
		}
		column[i] = sum;
		clow += sum;
		sum = 0;
	}

	ll low = 0, high = crow, mid;
	while(low < high){
		mid = (low+high)/2;
		int result = check(row, mid);
		if(result == 0){
			break;
		}
		else if(result == -1){
			high = mid-1;
		}
		else if(result == 1){
			low = mid+1;
		}
	}

	int k = 1;
	for(int i=0; i<p; i++){
		printf("%d ", pointers[i]);
	}

	printf("\n");

	low = 0; high = clow;
	while(low < high){
		mid = (low+high)/2;
		int result = check(column, mid);
		if(result == 0){
			break;
		}
		else if(result == -1){
			high = mid-1;
		}
		else if(result == 1){
			low = mid+1;
		}
	}

	for(int i=0; i<p; i++){
		printf("%d ", pointers[i]);
	}

	printf("\n");

	return 0;
}