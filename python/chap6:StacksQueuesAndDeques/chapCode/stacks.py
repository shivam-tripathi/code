'''
Stacks is collection of objects that are inserted and removed in last in and
first out principle (LIFO). Fundamental operations are pushing and pulling.
Common uses:
Internet browsers : Recently visited site's address is stored in a stack. Once
the new site is visited, it is pushed in. When back button is pressed, the last
item is popped to get the previous item.
Text editor's undo
'''

# Stacks as an abstract data type.

'''
Common properties are :
S.push(e)
S.pop()
S.top()
S.isEmpty()
len(S)

To maintain the abstraction of the stacks, list is not used, as it has other
features too. Stacks can be implementes with the help of lists though.
Adapter pattern:
It is a design wherein we want to modify an existing class's behaviour, so that
it matches a related, but different class or interface.
The new class is defined in a way sucj that it contains an instance of the
existing class in hidden manner, then implement each behaviour of the new class
using methods of this instance variable.
'''

class Empty(Exception):
    pass

class ArrayStack:

    def __init__(self):
        self._stack = []

    def __len__(self):
        return len(self._stack)

    def push(self, e):
        self._stack.append(e)

    def top(self):
        if self.isEmpty():
            return Empty('stack is empty')
        return self._stack[-1]

    def pop(self):
        if self.isEmpty():
            raise Empty('Stack is empty')
        return self._stack.pop()

    def isEmpty(self):
        if self._stack:
            return False
        else:
            return True


S = ArrayStack( )
S.push(5)
S.push(3)
print(len(S))
print(S.pop( ))
print(S.isEmpty( ))
print(S.pop( ))
print(S.isEmpty( ))
S.push(7)
S.push(9)
print(S.top( ))
S.push(4)
print(len(S))
print(S.pop( ))
S.push(6)

'''
Running time:
S.pop()       O(1)
S.push(e)     O(1)*
S.top()       O(1)
S.isEmpty()   O(1)
len(S)        O(1)
*amortised time
pop() has amortised time as it might need to resize the list.
Amortisation can be avoided by fixing the maximum size of stack, and at the same
storing number of elements in the stack.

'''

# Reversing a sequence using an stack.

'''
Once a stack is emptied, it gives back the elements in reverse order.
'''


def reverseFile(fname = 'out'):
    S = ArrayStack()
    handle = open(fname)
    for line in handle:
        S.push(line.rstrip('\n'))
    handle.close()

    output = open(fname, 'w')
    while not S.isEmpty():
        output.write(S.pop() + '\n')
    output.close()

reverseFile()
reverseFile()

# Delimiters

'''
If the opening delimiter is found, it is pushed into the stack. If closing
delimiter is found, previous delimiter is poped. If it doesn't match the closing
then pattern is wrong. If stack is found empty upon finding an closing delimiter
then also the pattern is wrong. Upon traversing all the elements, any opening
delimiter is left, then also it is wrong; but if it is empty then it is correct.
'''

def match(expression):
    lefty = '({['
    righty = ')}]'
    S = ArrayStack()
    for c in expression:
        if c in lefty:
            S.push(c)
        elif c in righty:
            if S.isEmpty():
                return False
            if righty.index(c) != lefty.index(S.pop()):
                return False
    return S.isEmpty()

print(match('()(()){([()])}'))
print(match(')(( )){([( )])}'))
print(match('[(5+x)-(y+z)]'))

# HTML Tags

'''
HTML documents are limited by tags.
'''

def html(fname = 'out'):
    handle = open(fname)
    raw = []
    for lines in handle:
        raw.append(lines)
    raw = ''.join(raw)
    S = ArrayStack()
    j = raw.find('<')
    while j != (-1):
        k = raw.find('>',j+1)
        if k == (-1):
            return False
        tag = raw[j+1:k]
        if not tag.startswith('/'):
            S.push(tag)
        else:
            if S.isEmpty():
                return False
            if tag[1:] != S.pop():
                return False
        j = raw.find('<',k+1)
    return S.isEmpty()

print ('>>', html())
