# Construction and analysis of dynamic array.
# Support for low level arrays is given by module ctypes.

import ctypes

class DynamicArray:

    def __init__(self):
        ''' Here we create an array with number of element = 0 and capacity = 1
        '''
        self._n = 0
        self._capacity = 1
        self._A = self._make_Array(self._capacity)
        # the raw array is declared in the _make_Array function.

    def __len__(self):
        return self._n
        # return number of elements in the array

    def __getitem__(self, k):
        if not 0 <= k < self._n :
            raise IndexError('invalid index')
        return self._A[k]
        # return element at index k

    def append(self, obj):
        if self._n == self._capacity:
            self._resize(2 * self._capacity)
        self._A[self._n] = obj
        self._n += 1
        # insert the object at the end of the list

    def _resize(self, size):
        B = self._make_Array(size)
        for k in range(self._n):
            B[k] = self._A[k]
        self._A = B
        self._capacity = size

    def _make_Array(self, size):
        return (size * ctypes.py_object)()

    def insert(self, k, value):
        if not(0 <= k <= self._n-1):
            raise IndexError('invalid index')
        if self._n == self._capacity:
            self._resize(2 * self._n)
        for j in range(self._n - 1, k-1, -1):
            self._A[j+1] = self._A[j]
        self._A[k] = value
        self._n += 1

    def remove(self, value):
        for k in range(self._n):
            if self._A[k] == value:
                for k1 in range(k,self._n - 1 ):
                    self._A[k1] = self._A[k1 + 1]
                self._A[self._n-1] = None
                self._n -= 1
                return
        raise ValueError("no such value in the list")

arr = DynamicArray()
for i in range(10):
    arr.append(i)
for i in range(10):
    print ((arr[i]))
print ('Length:',len(arr))

arr.insert(4,'a')
print (list(arr))

arr.remove('a')
print (list(arr))

'''
constructor(object)
object.function()
__contructors__()
function()
_constructor_variables
raise <errorName>('Message')
_internalFunctions()
errorsAreUsuallySmallCased
'''

# Amortized analysis of Dynamic Array.

'''
Using algorithmic design pattern called amortization, analysis of dynamic array
is done. Amortization does not concern itself with worst case scenario, rather
stresses on it's perfomance in average case/ in practice.
Aggregate method, accounting method and potential method.
Using accounting method, if charge of append is 1 unit, and we overcharge simple
append by 2 units, when increase in capacity occurs at 2^i position, the cells
from 2^(i-1) to (2^i - 1)  pay up for this appending. This causes append to
occur in constant time O(1), making the entire operation to finish in O(n) time.

O(1) amortization time can be proved for any geometrically increasing
progression of arrays. When choosing the geometric base, there exists a trade
off between size and run time. For example, if we choose base to be 2, the array
in the end turns out to be double the time. If we choose it to be 25% increase,
it turns out to be 1.25 times in size. But it will more frequent resizing, and
hence more time. The key to perfomance is amount of additional space is
proportional to the current size of array.
Using fixed size increment for each resize will result in Arithmetic progression
causing omega(n^2) time.
'''

'''
Amortized analysis is used when an occasional operation is slow, others are fast.
Analysis of a sequence of operations is done, and a guarantee of a worst case
time of a particular expensive operations. Hash tables, disjoint sets, splay
trees use this.
By asymptotic analysis, we would have concluded that by worst case insertion,
simple append would be O(n). But using amortization, we can prove that the cost
of append is O(1), as for the expensive operation would be amortized over
previous appends.
For example, hash tables also use dynamic array. There is a tradeoff between
size and time. If the size is big, search becomes fast. But the space used
increases.
This doesnot involve probability. Randomisation algorithms use probability to
prove the running time is less than worse case running time.
By Aggregate method, the above can be proved, by : 1 + (1+1) + 1 + 1 + 1 +
= (1 + 1 + 1 + 1 .. n terms) + (1 + 2 + 4 + 8 + .. log(2)(n-1) terms) < n.
'''

'''
Memory usage and shrinkage of an array
Final size of an array is proportional to overall number of elements, giving it
O(n) time.
If a container involves removal and resizing of itself, care must be taken that
array capacity is proportional to number of elements. Or else array size might
grow arbitrarily large, and that there will no longer be a proportional
relationship between array size and number of elements once elements have been
removed.
Robust implement will not just increase, but also shrink incase the size
decreases.
'''
