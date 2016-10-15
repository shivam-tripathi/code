#include <stdio.h>

int main(int argc, char* argv[]){
	union{
		short s;
		char c[sizeof(short)];
	} un;

	un.s = 0x0102;

	printf("%d %d\n",un.s, sizeof(short));
}
