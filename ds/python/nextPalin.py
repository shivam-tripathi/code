# This simple program calculates the next palindrome number after the given
# number.
# It's performance can be improved though.

num = list(input())
numcopy = int(''.join(num))
l = len(num)
bool = True

# Half the elements have to be copied.
lim = l//2

# To remove repeated code, k is used to distinguish between even and odd length
if l%2 == 0: k = -1
else : k = 0

# To avoid multiple comparisons, modified version of do while.
while bool:
    palin = num[0:lim] # First half is kept for palindrome.
    revPalin = [palin[i] for i in range(lim-1,-1,-1)] # First half is repeated.
    if l % 2 == 0 : palin = palin + revPalin
    # Add the middle element in case of odd length.
    else : palin = palin + [num[lim]] + revPalin

    # If the formed number is smaller than the original number a simple
    # increment in the middle number will give desired results.
    if ( int(''.join(palin)) < numcopy):
        num[lim + k] = str(int(num[lim + k]) + 1)
    else :
        bool = False

print (int(''.join(palin)))
