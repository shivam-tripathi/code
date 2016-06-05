/*
Storage class defines the scope (visibility) and life-time of any variable in C.
Functions can also have these storage class defining them.
These specifiers precede the type they modify.
1. auto
2. register
3. static
4. extern

Auto storage class variables are restricted to the function they are defined in,
that is, these are local variables.
All variables defined in a function are by default auto.

Register storage class variables are stored in the register instead of RAM.
This restricts the size of the variable to the register size. Also as the
variable is not saved in the RAM, there is no memory address. So &variable is an
error.
These should be used only for the variables that require quick access, like
counters in a program. Also, defining a variable does not mean that the variable
will be stored in the register. It might be stored in the register, depending
upon the hardware and implementation restrictions.

Static storage class
It instructs the compiler to keep a local variable in existence during the
lifetime of the program, instead of destroying every time getting it gets out
of scope.
This makes a variable retain value between function calls.
Static modifier can also be added to the global variables. This causes that
variable to be restricted in the file it declared, and cannot be accessed by
any other program in the same file.
When a variable is declared static, only one copy is shared by all the blocks
where it is in scope.

Extern class
See storageClassSupport.c
*/


#include <stdio.h>

// A global variable
static int counter = 5;
int globalCounter = 5;

void decrement(void);
extern void printCouter(void);

void main(void){
    while (counter--){
        printf("main : counter : %d \n", counter);
        printCounter();
        decrement();
    }
}

void decrement(void){
    printf("decrement : counter : %d \n", counter);
    printCounter();
    static int i = 5;
    globalCounter--;
    printf("%d %d\n", i++, counter);
}

/*
Further research :
    Storage class in functions?
    http://www.tutorialspoint.com/cprogramming/c_variable_arguments.htm
    http://www.tutorialspoint.com/cprogramming/c_memory_management.htm
*/
