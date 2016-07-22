'''
In python maximum recursion depth can be modified:
    import sys
    sys.getrecursionlimit()
    sys.setrecursionlimit(<value>)
Default is 1000
'''
# finding fibonacci series
# Inefficient method

from time import time
a = time( )

def fibonacci(n):
    if n == 0:
        return 1
    if n == 1:
        return 1
    return (fibonacci(n-1) + fibonacci(n-2))

def fibonacciSeries(n):
    for i in range(n):
        print(i,' ',fibonacci(i))

fibonacciSeries(10)

b = time( )
print(b-a)

# More efficient methods


a = time( )
def fibonacci_(n, a, b):
    if n == 0:
        print ('\t',a)
        return
    else:
        print ('\t',a)
        return fibonacci_ (n-1, b, a+b)

def fibonacciSeries_(n):
    fibonacci_(n-1,1,1)

fibonacciSeries_(10)

b = time( )
d2 = b-a
print(d2)


a = time( )
def good_fibonacci(n):
    '''Return pair of Fibonacci numbers, F(n) and F(n-1).'''
    if n <= 1:
        print ('#',n)
        return (n,0)
    else:
        (a, b) = good_fibonacci(n-1)
        print (a,'>>',a+b)
        return (a+b, a)

good_fibonacci(10)
b = time( )
d3 = (b-a)
print (d3)

if (d2 > d3):
    print("d3")
else :
    print("d2")
