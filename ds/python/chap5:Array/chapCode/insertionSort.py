'''
Insertion sort.
This is an online algorithm, sorts one by one. First the first element is
considered. It is already sorted. Then next element is considered, and is placed
in sorted position with respect to the array of element before it.
'''

def insertionSort(arr):
    sarr = [None] * len(arr)
    sarr[0] = arr[0]
    for i in range(1,len(arr)):
        j = i
        while j > 0 and sarr[j-1] < arr[i]:
                print(j)
                sarr[j] = sarr[j-1]
                j -= 1
        sarr[j] = arr[i]
    return sarr

def insertion_sort(A):
    for k in range(1,len(A)):
        cur = A[k]
        j = k
        while j > 0 and A[j-1] < cur:
            A[j] = A[j-1]
            j -= 1
        A[j] = cur
    return A

arr = list(map (int, input().split()))
print ('Sorted Array', insertion_sort(arr))
print ('Sorted Array',insertionSort(arr))
print(arr)


