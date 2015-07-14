'''
Properties to look for if a problem can be solved using dynamic programming
approach:
Overlapping subproblems
Optimal Substructures
These two are characteristic of dynamic programming.

Overlapping subproblems combines solutions of subproblems to reach a problem's
solution. Dynamic programming is mainly used when same subproblem is used again
and again.
In dynamic programming method, these subproblems are stored in a table so that
they donot have to be computed again and again.
So use of dynamic programming is useful only when there is reuse of a previously
calculated result.
For example in fibonacci series, there a number of solutions which are reused.

There are two different methods to solve these problems:
Memoization : Top-down
Tabulation : Bottom-up

Memoized form is similar to the recursive version, except that it looks up a
table like hash table to see if the solution has already been calculated.

Memoization versus Tabulation:
    Tabulation means bottom-up i.e. solving all subproblems and storing their
    results in a table to look them if they are needed again in future.
    This is usually done using a n-dimension table.

    Memoization on the other hands starts top to bottom. It recursively
    calculates the problem, starting with the biggest subproblem, and storing
    all the results calculated in the process in an array.

    When to use when?
    When all the subproblems have to be necessarily calculated, then bottom-up
    is better than top up by a constant factor, due to no overhead because of
    recursion and less overhead for maintaining table.
    Also in some problems (which ones ?), the regular pattern of accessing table
    can be exploited to reduce space-time complexity.
    If all the subproblems need not be solved then definitely memoisation is
    better.

In memoised form the table entry is filled on demand, while in tabulation all
entries starting from the bottom are filled.

'''

def memoisedFibo(n, lookup):
    if lookup[n] == None :
        if n <= 1 :
            lookup[n] = 1
        else :
            memoisedFibo(n-1, lookup)
            memoisedFibo(n-2, lookup)
            lookup[n] = lookup[n-1] + lookup[n-2]


def tabulationFibo(lookup, n):
    for i in range(n+1):
        if i <= 1 :
            lookup[i] = 1
        else :
            lookup[i] = lookup[i-1] + lookup[i-2]


print ("Input sequence number :")
n = int(input())
lookup = [None] * n
memoisedFibo(n-1,lookup)
print (lookup[n-1])

_lookup = [None for i in range(n)]
tabulationFibo(_lookup, n-1)
print (_lookup[n-1])


''''
Further reading : Ugly numbers method 2, http://www.spoj.com/problems/LKS/ knapsack
'''
