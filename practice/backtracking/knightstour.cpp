#include <stdio.h>
using namespace std;

#define N 8

/*
 * Change in value of N calls for change in value of xmove and ymove which store 
 * the value of next move relative to present position.
*/

bool solveKUtil(int x, int y, int movei, int sol[N][N], int xmove[], int ymove[]);

bool validMove(int x, int y, int sol[N][N]){
	return (x>=0 && x<N && y>=0 && y<N && sol[x][y] == -1); 
}

void print(int sol[N][N]){
	for(int x = 0; x < N; x++){
		for(int y = 0; y < N; y++){
			printf("%2d  ", sol[x][y]);
		}
		printf("\n");
	}
}

bool solveKT(){
	int sol[N][N];

	for(int x=0; x<N; x++){
		for(int y=0; y<N; y++){
			sol[x][y] = -1;
		}
	}
	int xmove[N] = {2, 1, -1, -2, -2, -1, 1, 2};
	int ymove[N] = {1, 2, 2, 1, -1, -2, -2, -1};

	sol[0][0] = 0;

	if(!solveKUtil(0, 0, 1, sol, xmove, ymove)){
		printf("No solution\n");
		return false;
	}
	else{
		print(sol);
		return true;
	}
}

bool solveKUtil(int x, int y, int movei, int sol[N][N], int xmove[], int ymove[]){
	int next_x, next_y;
	if(movei == N*N)
		return true;

	for(int k=0; k<N; k++){
		next_x = x + xmove[k];
		next_y = y + ymove[k];

		if(validMove(next_x, next_y, sol)){
			sol[next_x][next_y] = movei;
			if(solveKUtil(next_x, next_y, movei+1, sol, xmove, ymove)){
				return true;
			}
			else{
				sol[next_x][next_y] = -1;
			}
		}
	}
	return false;
}

int main(){
	solveKT();
	return 0;
}