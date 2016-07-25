/*
 * Use binary search
 * Find number of occurences in a sorted array
 *
 */

#include <bits/stdc++.h>
using namespace std;

int cmp(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}


// Simple and straight forward : find all occurences of the variable and then for each occurence add
// one to the output

int search(int a[], int start, int end, int elem){
	int mid;
	while(start <= end){
		mid = (start+end)/2;
		if(a[mid] == elem){
			return 1+search(a, start, mid-1, elem)+search(a, mid+1, end, elem);
		}
		else if(a[mid] < elem)
			return search(a, mid+1, end, elem);
		else 
			return search(a, start, mid-1, elem);
	}
	return 0;
}


// Another method is to note that as the array is sorted, if we find the first occurence and the last 
// occurence, subtract them and add one to get total number of occurences 
int search_modified(int a[], int start, int end, int elem, int op){
	int mid;
	while(start <= end){
		mid = (start+end)/2;
		if(a[mid] == elem){
			if(op == 1){
				int index = search_modified(a, start, mid-1, elem, 1);
				return (index == -1 ? mid : index);
			}
			if(op == 2){
				int index = search_modified(a, mid+1, end, elem, 2);
				return (index == -1 ? mid : index);
			}
		}
		else if(a[mid] < elem){
			return search_modified(a, mid+1, end, elem, op);
		}
		else {
			return search_modified(a, start, mid-1, elem, op);
		}
	}
	return	-1;
}


int count_modified(int a[], int size, int elem){
	int first = search_modified(a, 0, size-1, elem, 1);
	int second = search_modified(a, 0, size-1, elem, 2);
	if (first == -1 && second == -1)
		return 0;
	return second-first+1;
}

int count(int a[], int size, int elem){
	return search(a, 0, size-1, elem);
}

int main(){
	int size, elem;
	cin >> size >> elem;
	int a[size];
	for(int i=0; i<size; i++){
		cin >> a[i];
	}

	qsort(a, size, sizeof(int), cmp);

	// cout << count(a, size, elem) << endl;
	cout << count_modified(a, size, elem) << endl;

}
