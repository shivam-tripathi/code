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

    def __getintem__ (self, k):
        if not 0 <= k < self._n :
            raise IndexError('invalid index')
        return self._A[k]
        # return element at index k

    def append(self, obj):
        if self._n == self._capacity:
            self.resize(2 * self._capacity)
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
        return (size * ctypes.py_oject)()


arr = DynamicArray()
arr.append(2)
print(arr)
len(arr)
