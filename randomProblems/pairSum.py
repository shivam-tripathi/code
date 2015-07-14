# A simple program to find the number of pairs of numbers given in a sequence
# which are divisible by a number k.

# A list to store the total number of elements giving value equal to the index
# upon modulus with k. Hence the range of indexes equal to 0->k-1.

k = int(input())
arr = map(int,input().split())

a= [0 for i in range(0,k)]
for i in arr:
    a[i % k] += 1

# If sum of the modulus is equal to the number k, then the numbers are divisible
# with the number k.
# In all cases, even or odd, the elements 1 will add up with elements (k-1), 2
# with (k-2) and so on.
# As a result, index will vary from 1 to (k-1)/2. If k/2 index is not same as
# (k-1)/2, it can form pairs among itself. Same thing for elements at 0 index.
def C(n): return n *  (n-1) / 2

lim = (k-1)//2
ans = 0
for i in range(1, lim+1):
    ans += a[i] * a[k-i]
if (k % 2 ==0):
    ans += C(a[k//2])
ans += C(a[0])
print (int(ans))
