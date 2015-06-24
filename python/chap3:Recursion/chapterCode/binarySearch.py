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
