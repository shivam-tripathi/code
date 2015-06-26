'''
Binary search uses a sorted array to returns True if present.
Linear search or sequential search uses unsorted list, and iterates over each
element.
'''

def binSearch(arr):
    print ('Element to be searched:')
    elem = int(input())
    l = len(arr)
    print(main(arr, elem, 0, l-1))

def main(arr, elem, lower, upper):
    if lower > upper:
        return False
    mid = (lower+upper)//2
    if arr[mid] == elem:
        return True
    elif arr[mid] > elem:
        upper = mid - 1
        return main(arr, elem, lower, upper)
    elif arr[mid] < elem:
        lower = mid + 1
        return main(arr, elem, lower, upper)

a = sorted(list(map ( int, input().split())))
binSearch(a)


'''
Major realisation here is that every element is bigger than the one before it.
So one does not have to cover all cases. We can remove all those cases where it
will definitely not occur, and check in therefore the possible location. As it
is Binary search, we use recursion to break array/list into two parts, reject
one and check in the other by breaking it up too.

This sorted approach comes in handy in many other cases, sometimes in dynamic
programming. (I have quite little knowledge in this presently).
'''
