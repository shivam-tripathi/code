
'''
The list class in python doesn't exactly use geometrical increment in array nor
arithmetical progression. But still, it uses amortized constant time to append.
'''

from time import time
import sys
import math

for i in range(1,9):
    data = []
    n = int(math.pow(10,i))
    print (n)
    start = time()
    for k in range(n):
        data.append(n)
    end = time()
    print ((end - start)/n)

'''
10
5.483627319335937e-07
100
1.8835067749023438e-07
1000
1.8620491027832032e-07
10000
1.839160919189453e-07
100000
1.8343210220336914e-07
1000000
1.828138828277588e-07
10000000
1.7925207614898683e-07
100000000
1.898135995864868e-07

Using this result, we can see that there is no clear relation between n and
average time.
'''
