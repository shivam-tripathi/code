#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[], int start, int end, int num){
	int mid = (start+end)/2;
	while(start <= end){
		if(a[mid] == num)
			break;
		else if(a[mid] < num)
			start = mid+1;
		else 
			end = mid-1;
		mid = (start+mid)/2;
	}
	
	if(num < a[0])
		return 0;
	if(num > a[size-1])
		return size-1;

	if(a[mid] == num)
		return mid;

	if(mid >= 0 && a[mid]<num)
		return mid;
	if(mid < size && a[mid]>num)
		return mid-1;
}

int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(int argc, char const *argv[])
{
	int size, num;
	cin >> size >> num;

	int a[size];

	for(int i=0; i<size; i++)
		cin >> a[i];

	qsort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), cmp);

	for(int i=0; i<size; i++)
		cout << a[i] << " ";
	cout << endl;

	int index = binary_search(a, size, num);

	return 0;
}
