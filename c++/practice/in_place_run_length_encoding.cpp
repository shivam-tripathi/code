// Inplace run length encoding

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char  *argv[])
{
	if(argc == 1)
		return 0;
	char *original = argv[1];
	int size = strlen(argv[1]);
	int iterate=0, update=0, count=0;
	char prev=original[0];
	int single_count = 0;
	cout << original << endl;
	while(iterate <= size){
		if(original[iterate] == prev){
			count++;
			iterate++;
			continue;
		}
		// update
		original[update++] = -1 * (int)prev;

		if(count > 1)
			original[update++] = count;
		else
			single_count++;
		// reinitialize
		prev = (char)original[iterate];
		count=0;
	}


	update -= 1;

	int final_update = update + single_count;
	int temp = final_update;


	while(update>=0){
		if(original[update] < 0){
			original[final_update--] = 1;
			original[final_update--] = original[update--] *-1;
		}
		else {
			original[final_update--] = original[update--];
			original[final_update--] = (char)original[update--] * -1;
		}
	}

	for(int i=0; i<=temp; i++){
		if(i%2 == 0){
			cout << (char)original[i] << " ";
		}
		else {
			cout << (int)original[i] << " ";
		}
	}
	cout << endl;
	return 0;
}
