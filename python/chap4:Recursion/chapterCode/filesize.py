'''
Python's os module, has following useful functions:
    os.path.size(<path>) :: gives immediate file size
    os.path.isdir(<path>) :: returns Boolean depending it being a directory
    os.listdir(<path>) :: List of strings of all entries in the directory
    os.path.join(path, filename) :: Compose the path string using separator
'''
import os

def sizes(fname):
    total = os.path.getsize(fname)
    if os.path.isdir(fname):
        sub = os.listdir(fname)
        for i in sub:
            fname_ = os.path.join(fname, i)
            total += sizes(fname_)
    print ( '{0:<11}'.format(total), fname)
    return total

fname = input()
print(sizes(fname))

