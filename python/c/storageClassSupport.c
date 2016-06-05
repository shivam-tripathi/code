/*
Extern variables in C
Using extern keyword, a program can access global variable/function of any other
program if it not restricted to the same file by static storage class.
Declaring a variable/function extern means that the original reference of
function/variable will be picked up.
All the files sharing such functions/variables have to be compiled together.
    _:/~/$ gcc <file1> <file2>
*/

#include <stdio.h>

extern int globalCounter;

void printCounter(void){
    printf("globalCounter : %d\n", globalCounter);
}
