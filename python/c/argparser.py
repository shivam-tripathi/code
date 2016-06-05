'''
Argparse is the recommended command line parsing module in Python standard
library. Similar module is getopt ( Python version of C module with the same
name).
'''

import argparse

parser = argparse.ArgumentParser(description =
    "Trial of argparser module of Python standard library.")
group = parser.add_mutually_exclusive_group()

#Add_mutually_exclusive_group() helps us to specify conflicting types.
#Created group always takes optional conflicting arguments.

parser.add_argument("echo", help = "echo the string that you type here!")

parser.add_argument("square", help = "displays sqaure of the number!",
    type = int, choices = [1,2,3,4,5,6,7])

group.add_argument("-q", "--quiet", action = "store_true")

group.add_argument("-v","--verbosity", help = "increase output's verbosity",
    action = "count", default  = -1)

#add_argument specifies which command line argument program is willing to accept
#In above part, it adds positional arguments

#default field sets the default value of optional argument

#If optional argument is not used, the relevant variable is given value None.

args = parser.parse_args()
#parse_args() returns some some data from the arguments specified

#action makes the argument more of a flag, by assigning some operation to it.
#For example, action = "store_true" makes the verbose true if mentioned in the
# argument list. Not specifying the argument will mean False.

#action = "count" count number of times the argument type is specified, and this
#is the value stored in this optional argument. Counting starts from 0.

#choices field restricts the choice of value one can input as arguments.

if args.quiet :
    print (args.square ** 2)
elif args.verbosity >= 2:
    print ('The square {} is {}'.format(args.square, args.square ** 2))
elif args.verbosity >= 1:
    print ('{} ^ 2 = {}'.format(args.square, args.square ** 2))
else :
    print (args.square ** 2)
print (args.echo)
print (args.verbosity)
print (args.square ** 2)
