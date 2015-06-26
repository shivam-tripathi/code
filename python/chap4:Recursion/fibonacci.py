'''
In python maximum recursion depth can be modified:
    import sys
    sys.getrecursionlimit()
    sys.setrecursionlimit(<value>)
Default is 1000
'''
# finding fibonacci series
# Inefficient method

def fibonacci(n):
    if n == 0:
        return 1
    if n == 1:
        return 1
    fibonacci(n-1) + fibonacci(n-2)

def fibonacciSeries(n):
    for i in range(n):
        print(fibonacci(n))

fibonacciSeries(10)
