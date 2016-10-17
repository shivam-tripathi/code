/* Given a number N, print all its unique prime factors and their powers in N */

#include <stdio.h>
using namespace std;

#define SIZE 10000+3

int main(int argc, char const *argv[]){
	int seive[SIZE] = {0};

	for(int i=2; i<SIZE; i++){
		if(seive[i] == 0){
			for(int j=i; j<SIZE; j += i){
				if(!seive[j])
					seive[j] = i;
			}
		}
	}

	seive[1] = 1;

	/*for(int i=0; i<20; i++){
		cout << i << " " << seive[i] << endl;
	}
	*/

	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		int prime = seive[n];
		int count = 1;
		int check = n/prime;
		while(check){
			if(seive[check] == prime){
				count ++;
				check = check/prime;
			}
			else{
				printf("%d %d ", prime, count);
				prime = seive[check];
				count = 1;
				check = check/prime;
			}
			if(prime == 1)
				check = 0;
		}
		printf("\n");
	}
	return 0;
}