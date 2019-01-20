#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[], int start, int end, int num){
	int mid, size = end+1;
	while(start <= end){
		mid = (start+end)/2;
		if(a[mid] == num)
			break;
		else if(a[mid] < num)
			start = mid+1;
		else 
			end = mid-1;
	}
	return mid;
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

	cout << "Sorted array : ";
	for(int i=0; i<size; i++)
		cout << a[i] << " ";
	cout << endl;

	int index = binary_search(a, 0, size-1, num);

	if(a[index] > num){
		if(index > 0)
			index = index-1;
		else index = 0;
	}

	if(a[index] < num){
		if(index < size-1)
			index += 1;
		else index = size-1;
	}

	cout << index << endl;

	return 0;
}
