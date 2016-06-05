/*
Recently some problem I came across required a method to check if a number is
power of two or not. The method I found was quite intresting one. So I decided
to look a bit more into these "bit-twiddling" methods.
So here are the "bit-twiddling" hacks by Sean Eron Anderson.

The six bit-wise operator in C are:
&   bitwise AND
|   bitwise inclusive OR
^   bitwise exclusive OR
<<  left shift
>>  right shift
~   one's complement (unary)
These may only be applied integral operands, i.e. short, int, long and char.
*/

#include <stdio.h>


// Finds the sign of a number
void sign(){
    int v, sign1, sign2, sign3;
    printf("Enter the number whose sign is to found!\n");
    scanf("%d", &v);
    sign1 = -(v<0);
    // If the number is less than 0, it evaluates to 1, then to -1. Otherwise 0.

    sign2 = -(int)(unsigned int)
    printf("%d %d %d\n", sign2, sign2, sign1);
}


// Finds the if two integers are of opposite sign.
void oppSign(){
    int x, y;
    printf("Enter the 2 integers whose sign is to be compared!\n");
    scanf("%d %d", &x, &y);
    int ans = ((x ^ y ) < 0);
    printf("%d\n", ans); // 0 if of same sign, else 1.
}

// Compute absolute value
void abs(){
    printf("Enter number whose absolute value is to be found!\n");

}

void bitOperations(void){
    int x, n, y;

    // a << b is effectively a * 2^b.
    // a << b if a is unsigned integer always adds zero.
    // In unsigned integers results in zero on my system. But it may be filled
    // with arithmetic shift/bit signs in some other machines (K&R).
    printf("Enter numbers a and b in a << b\n");
    scanf("%d %d", &x, &n);
    y = x<<n;
    printf("a<<b = %d\n", y);

    // a >> b is effectively a / (2^b) for unsigned integers.
    // For unsigned integer it removes last n bits.
    // For negative number, for sake of remembering, it gives -((abs a)/(2^b)+1)
    printf("Enter number in a>>b\n");
    scanf("%d %d", &x ,&n);
    y = x >> n;
    printf(" %d >> %d = %d\n", x, n, y);

    // & is bit-wise and. It is used to remove the last bits from a number, for
    // example using _ & 8 means last 3 bits will be made 0, and the 4th one
    // will depend on the value of the number.
    printf("Enter a and b in expression a & b\n");
    scanf("%d %d", &x, &n);
    y = x & n;
    printf("%d & %d = %d\n", x, n, y);
    printf("%d & %d = %d\n", toBits(x), toBits(n), toBits(y));

    // | is bit-wise or. It is used to make the last bits equal to one.
    printf("Enter a and b in expression a | b\n");
    scanf("%d %d", &x, &n);
    y = x | n;
    printf("%d & %d = %d\n", x, n, y);
    printf("%d & %d = %d\n", toBits(x), toBits(n), toBits(y));

    // ^ is exclusive or. If the bits are same on both sides, it returns 0, else
    // 1.

    // ~ is one's complement. It turns 0s to 1 and 1s to 0.

}


// Converts positive decimal to binary number.
// Needs improvisations to include negative numbers.d
int toBits(n){
    if (n >= 0){
        int c = 0;
        int trails = 1;
        while (n%2 == 0 && n){
            n /= 2;
            trails *= 10;
        }
        int tens = 1;
        while (n>0){
            c = c + ((n%2)*tens);
            n /= 2;
            tens *= 10;
        }
        c *= trails;
        return c;
    }
}


void main(void){
    oppSign();
}


// Successful execution of scanf returns number of successful inputs.
// What does printf return upon being called?
// Storage of negative integers in C?

