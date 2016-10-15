'''
Tuples
These support all the non-mutating behaviours of lists. Following are the
non-mutating behaviours (common to both lists and tuples) :
Operation-----------------------Running Time
len(data)-----------------------O(1)
data[j]-------------------------O(1)
data.count(value)---------------O(n)
data.index(value)---------------O(k+1)
value in data-------------------O(k+1)
data1 == data2------------------O(k+1)
(similarly !=, <, <=, >, >=)----O(n)
data[j:k]-----------------------O(k-j+1)
data1 + data2-------------------O(n1+n2)
c*data--------------------------O(c*n)

(== != < = > >=)
Comparision of two sequence occurs lexicographically. In worst case, it will
take running proportional to shorter of two sequences.
Slicing occurs [a:b] from index a to (b-1). One step is construction, rest
initialisation.
'''

'''
Mutating behaviours of lists

Operation-----------------------Running Time
data[j] = val-------------------O(1)
data.append(value)--------------O(1)*
data.insert(k, value)-----------O(n-k+1)*
data.pop( )---------------------O(1)*
data.pop(k)---------------------O(n-k)*
del data[k]---------------------O(n-k)*
data.remove(value)--------------O(n)*
data1.extend(data2)-------------O(n2)*
data1 += data2------------------O(n2)*
data.reverse( )-----------------O(n)
data.sort( )--------------------O(nlog n)
*amortized


insert => In worst case, append requires omega(n), but amortised time is O(n).
In insert, all elements are copied in reverse, to the index before them. Finally
at the kth index the value is inserted. Inserting at 0 th index is always most
expensive.
remove, pop => pop() is O(1), but bound is amortised, as shrinking also takes
place occasionally. pop(k) is O(n-k), and similar to insert, pop(0) is most
expensive. When removal is by index, like in pop or in del, it is O(n-k), as it
starts in reverse. When removal is by value, like in remove, it is O(n), as
removal is of the first occurence of the value.
extend is better than one by one append, as it uses natively compiled code
instead of interpreted script, there is less overhead to call one function that
does all the operations than call same function repeatedly, and the last is that
the size of updated list is calculated in advance. This is beneficial, as if the
size of the second list is large, many resizes might be made. But in extend,
only resizes is needed, if at all needed.

List comphrehensions are significantly faster than repeated appends to a list.
[x*x for x in range(10) if x%2 == 0]
Always try to use list comphrehensions to create lists.

Note : sorted takes input type as a sequence and returns a sorted list.
'''

'''
String classes
Just k generally is used to denote index, n is used to denote length of strings.
For operations that rely on pattern of strings, m is used to denote the length.

Pattern matching

Composing strings
As strings are immutable, (+=) operator produces a new string every time. It
must be avoided every time. Instead, a list can be made if regular appends are
needed, which can be joined later using the str.join(list) function.
If string is composed using (+=) then it would O(n^2). Using join assures O(n).
First O(n) amortised time will be taken for appending.

Some new implementations of python interpreter have optimised use of (+=)
operator. The += creates a new instance of str class, as if any other variable
refers to that object, as primarily strings are immutable. But if interpreter
some how knew that there were no other refrences to the instance under
consideration, it could implement string in a better manner as a dynamic array.
Python keeps something called reference counts for each object, to determine if
the object can garbage collected. But here it can be used for this very purpose.
'''
