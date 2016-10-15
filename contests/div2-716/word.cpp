#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string a;
	cin >> a;

	int end = 25, start = 0;

	bool occur[30] = {0};
	int index[30] = {0};

	bool flag = true;

	for(int i=start; i<=end; i++){
		if(a[i] == '?')
			continue;	

		int check = a[i] - 'A';

		if(occur[check] == true){
			start = index[check]+1;

			end = start + 25;
			
			if(end > a.length()-1){
				flag = false;
				break;
			}

			/* reset */
			for(int j=0; j<26; j++){
				index[j] = -1;
				occur[j] = false;
			}

			i = start;
		}

		else{
			index[check] = i;
			occur[check] = true;
		}
	}


	int p=0;

	if(flag == false){
		printf("%d\n", -1);
	}

	else{

		for(int i=0; i<a.length(); i++){

			if(i >= start && i <= end){

				if(a[i] == '?'){
					while(p<25 && occur[p]) p++;
					printf("%c", p+'A');
					p++;
				}

				else 
					printf("%c", a[i]);
			}

			else{
				if(a[i] == '?')
					printf("A");
				else 
					printf("%c", a[i]);
			}
			if(i == a.length()-1) printf("\n");
		}
	}
	return 0;
}