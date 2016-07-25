/*
Find a given pair with given sum in bst.

Method 1 : 
	Inorder traversal -> sorted array, find the element using binary search.
*/

#include <bits/stdc++.h>
using namespace std;


// Compare function for qsort
int cmp(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

// Binary search
int search(int a[], int size, int elem){
	int start = 0, end = size-1, mid;
	while(start<=end){
		mid = (start+end)/2;
		if(a[mid] == elem)
			return mid;
		else if(a[mid] < elem)
			start = mid+1;
		else 
			end = mid-1;
	}
	return -1;
}

// Struct for BST



int main(){
	int size, sum;
	cin >> size >> sum;
	int a[size];
	for(int i=0; i<size; i++){
		cin >> a[i];
	}


	for(int i=0; i<size; i++)
		cout << a[i] << " ";
	cout << endl;

	qsort(a, size, sizeof(a[0]), cmp);

	for(int i=0; i<size; i++)
		cout << a[i] << " ";
	cout << endl;

	int i=0, count=0; 
	while(a[i] <= sum/2.0){
		int index = search(a, size, sum-a[i]);
		if(index != -1 && index != i){
			count ++;
		}
		i++;
	}
	cout << count << endl;
}
