/*
 * Sort array of 0, 1 and 2 in place
 */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int size;
	cin >> size;
	int arr[size];
	for(int i=0; i<size; i++){
		cin >> arr[i];
	}

	int zero = 0, two = size-1, iterate = 0;

	while(iterate<=two){
		cout << iterate << " " << arr[iterate] << " | ";
		if(arr[iterate] == 0){
			if(iterate <= zero){
				iterate++;
				zero++;
			}
			else
				swap(arr[iterate], arr[zero++]);
		}
		else if(arr[iterate] == 2){
			swap(arr[iterate], arr[two--]);
		}
		else{
			iterate++;
		}
		for(int i=0; i<size; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	for(int i=0; i<size; i++){
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}
