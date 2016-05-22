'''
Linear recursion :: At most one more function call is made.
Trace of recursion calls is single sequence.
'''

# Sum of elements of a sequence recursively.
# Simple as in Haskell.
def sumSeq(arr):
    if arr == []:
        return 0
    return (sumSeq(arr[1:]) +arr[0])

#print (sumSeq(list(map(int, input().split()))))

# Reverse a sequence recursively
def reverse(arr, lower, upper):
    if lower >= upper:
        return (arr)
    arr[lower], arr[upper] = arr[upper], arr[lower]
    return reverse(arr, lower+1, upper-1)

#arr = list(map(int, input().split()))
#print (reverse(arr, 0, len(arr)-1))

# recursively calculating powers
def powElem(elem, power):
    if power == 0:
        return 1
    else:
        return elem*(powElem(elem,power-1))
# print(powElem(2,5))


