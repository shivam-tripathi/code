/*
 * Recursive in place run length encoding\
 * Recursive is always more elegant, less error prone and easy to debug
 */

#include <bits/stdc++.h>
using namespace std;

int recur(int update, int start_index, int size, char *original){
	if(start_index >= size)
		return update;
	int count = 0, i;
	char prev = original[start_index];
	for(i=start_index; i<size; i++){
		if(original[i] == prev)
			count++;
		else
			break;
	}
	int end = recur(update+2, i, size, original);
	original[update] = prev;
	original[update+1] = count;
	return end;
}


int main(int argc, char *argv[])
{
	if(argc == 1)
		return 0;
	char *original = argv[1];
	int size = strlen(argv[1]);
	int update = 0, start_index = 0;
	int end = recur(update, start_index, size, original);
	for(int i=0; i<end; i++){
		if(i%2 == 0)
			cout << original[i] << " ";
		else
			cout << (int)original[i] << " ";
	}
	cout << endl;
	return 0;
}
