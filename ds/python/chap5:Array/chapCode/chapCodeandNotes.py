'''
Python saves lists with elements of different sizes simply by not saving the
elements, but rather the 64 bit addresses in consequetive memory. This is how
Python ensures constant time access to elements of a list or tuple.

foo = bar means simply foo is an alias for bar, i.e. it refers to the same object
as the bar. Copy is different from aliasing.
foo = list(bar) generates a shallow copy. Shallow copy gives array of immutable
elements.
foo = copy.deepcopy(bar) gives a copy mutable in nature.

Strings, as opposed to lists and tuples are array not of references but of
characters. These are the compact as opposed to referential arrays of lists and
tuples.
Benefits of a compact array include lesser memory usage as there no overheads to
store memory addresses. One character stored in a compact array takes up 2 bytes
but the character storage in independant array will take up more space. Moreover
compact array enjoy better computing performance, as all elements are stored in
consequetive memory locations. In referential arrays, this is not the case, as
list has no hold as to where the element will be saved on the memory. It only
saves the location of each element's object.

The following chunk gives the size of any variable.
from sys import *
getsizeof(..)

Compact array is supported in python with the use of array module.
from array import *
primes = array( 'i' , [2, 3, 5, 7, 11, 13, 17, 19])

Code    data type in c          bytes
b       signed char             1
B       unsigned char           1
u       Unicode char            2/4
h       signed short int        2
H       unsigned short int      2
i       signed int              2/4
I       unsigned int            2/4
l       signed long int         4
L       unsigned long int       4
f       float                   4
d       float                   4

Module array does not support compact arrays of user defined types. For that
use ctypes.
Low level arrays require size of array to be given because it cannot extend into
nearby continuous memory locations, as the system might allocate them to other
variables.

In python, however this is not an issue.
Instances of str and tuple classes are immutable, so the correct
size for an underlying array can be fixed when the object is instantiated.

Lists use concept of dynamic array, as they support mutation.
Python does not reserve the space of list equal to the size of the input, but
more than that. Whenver something is to be appended to the list, it is done till
all reserve space is used up. Once this happens, class requests a larger array
with more reserved space and copies the contents to it, and system reclaims the
older array.
'''

import sys

def sizeOfList():
    arr syms = [] ,()
    for i in range(25):
        l = len(arr)
        ls = len(sym)
        size = sys.getsizeof(arr)
        print('Length : {0:3d}; Size in bytes : {0:5d}'.format(l,size))
        arr.append(None)

#sizeOfList()

# Dynamic array is not formed inside a function?
'''
#Output
Length :   0; Size in bytes :     0
Length :   1; Size in bytes :     1
Length :   2; Size in bytes :     2
Length :   3; Size in bytes :     3
Length :   4; Size in bytes :     4
Length :   5; Size in bytes :     5
Length :   6; Size in bytes :     6
Length :   7; Size in bytes :     7
Length :   8; Size in bytes :     8
Length :   9; Size in bytes :     9
Length :  10; Size in bytes :    10
Length :  11; Size in bytes :    11
Length :  12; Size in bytes :    12
Length :  13; Size in bytes :    13
Length :  14; Size in bytes :    14
Length :  15; Size in bytes :    15
Length :  16; Size in bytes :    16
Length :  17; Size in bytes :    17
Length :  18; Size in bytes :    18
Length :  19; Size in bytes :    19
Length :  20; Size in bytes :    20
Length :  21; Size in bytes :    21
Length :  22; Size in bytes :    22
Length :  23; Size in bytes :    23
Length :  24; Size in bytes :    24
'''

data = [ ]
for k in range(25):
    a = len(data)
    b = sys.getsizeof(data)
    print( 'Length: {0:3d}; Size in bytes: {1:4d}' .format(a, b))
    data.append(None)

'''
#Output
Length:   0; Size in bytes:   64
Length:   1; Size in bytes:   96
Length:   2; Size in bytes:   96
Length:   3; Size in bytes:   96
Length:   4; Size in bytes:   96
Length:   5; Size in bytes:  128
Length:   6; Size in bytes:  128
Length:   7; Size in bytes:  128
Length:   8; Size in bytes:  128
Length:   9; Size in bytes:  192
Length:  10; Size in bytes:  192
Length:  11; Size in bytes:  192
Length:  12; Size in bytes:  192
Length:  13; Size in bytes:  192
Length:  14; Size in bytes:  192
Length:  15; Size in bytes:  192
Length:  16; Size in bytes:  192
Length:  17; Size in bytes:  264
Length:  18; Size in bytes:  264
Length:  19; Size in bytes:  264
Length:  20; Size in bytes:  264
Length:  21; Size in bytes:  264
Length:  22; Size in bytes:  264
Length:  23; Size in bytes:  264
Length:  24; Size in bytes:  264
'''

'''
This here shows that even the empty list has some memory. This is because every
python variable requires some bytes of memory to maintain it's state, like the
a refrence to class it belongs. We cannot access the private variables of the
list, but some idea can be assumed, for variables storing number of elements,
maximum number of elements that can be stored, reference to currently allocated
array.
'''
