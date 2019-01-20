/*
Given an array A[] and a number x, check for pair in A[] with sum as x.

Method one:
	This method first sorts the array and then uses binary search to find the element.
	Quick sort is used as I needed to practice quicksort, you can replace and use any other sorting.

Method two:
	Use array mapping all numbers, if size is known (and size complexity is not too big).
	
	If range of numbers include negative numbers then also it works. All we have to do for negative 
	numbers is to make everything positive by adding the absolute value of smallest negative integer 
	to all numbers.
*/

#include <bits/stdc++.h>
using namespace std;

static int SIZE = 6;

// Quick sort code 

int partition(int a[], int start_index, int end_index){
	int temp = a[start_index], i=start_index, final=start_index;
	swap(a[start_index], a[end_index]);
	while(i < end_index){
		if(a[i] < temp){
			swap(a[start_index++], a[i]);
			final = i;
		}
		i++;
	}
	swap(a[start_index], a[end_index]);
	return start_index;
}

void quicksort(int a[], int start_index, int end_index){
	if(start_index >= end_index)
		return;
	int mid = partition(a, start_index, end_index);
	quicksort(a, start_index, mid-1);
	quicksort(a, mid+1, end_index);
	return;
}

// Binary search

int search(int a[], int size, int elem){
	int start = 0, end = size-1, mid;
	while(start <= end){
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


int main(int argc, char const *argv[])
{
	int size, sum;
	cin >> size >> sum;
	int a[size]; 
	for(int i=0; i<size; i++){
		cin >> a[i];
	}
	

	quicksort(a, 0, size-1);

	int i=0, count=0;
	while(a[i] <= sum/2.0){
		int index = search(a, size, sum-a[i]);
		if( index != -1 && index != i){
			count++;
		}
		i++; 
	}
	cout << count << endl;
	return 0;
}
