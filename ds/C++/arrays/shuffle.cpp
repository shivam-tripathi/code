// www.geeksforgeeks.org/shuffle-a-given-array
#include <bits/stdc++.h>
using namespace std;

#define NUM (rand()/(double)RAND_MAX)

void print(int arr[], int size) {
	for(int i=0; i<size; i++) cout << arr[i] << " ";
	cout << endl;
}

int main(int argc, char const *argv[]){
	int size;
	cin >> size;
	srand(time(NULL));

	int arr[size];
	for(int i=0; i<size; i++) {
		arr[i] = NUM * 10000;
	}

	print(arr, size);

	// The only important piece of code here 
	int index;
	for(int i=size-1; i > 0; i--) {
		index = rand()%(i+1); // Another method would be to use ((rand()/(double)RAND_MAX) * (i-1))
		cout << i << " with " << index << endl;
		swap(arr[i], arr[index]);
	}

	print(arr, size);

	return 0;
}


/* 
	The importance here is of the math - probability of every number to have a particular position 
	is exactly (1/n). This ensures proper randomness in shuffling.
*/