'''
English ruler is an example of fractal, i.e. example of self replicating
structures at various magnification level.
Major stick length is suppose l. Then the stick can be broken into two parts,
where each part will have one less size inserted till size becomes one.
'''


# Self implementation of the English ruler.
# The stick length is calculated recursively, and then strings corresponding to
# these length were calculated.
# This looks trivial now, but it took me around 15 minutes to figure this out,
# plus fifteen minutes to write it down :/.


def main(a, b, n):
    if n == 0:
        #print([a, b]) This statement will make it a bit clear.
        return [a, b]
    # Every tick has one less in size tick above and below. Supposing the tick
    # to inserted has size n, till n is greater than 1, ticks are inserted above
    # and below, and receiving these two arrays, we join them.
    lower = main(a, n, n-1)
    upper = main(n, b, n-1)
    return (lower + upper[1:])

# Base case here is that if n=0, then return array corresponding to the pattern.
# [_,1] or [1,_] is returned for every recursion.

def englishRuler():
    size = int(input())
    inches = int(input())
    ans = main(size, size, size-1)
    l = len(ans)
    for j in range(inches):
        for i in range(l-1):
            if i == 0: print('-'*ans[i],j)
            else : print('-'*ans[i])
    print('-'*ans[0],j+1)

englishRuler()
print()

# Chapter method relies on the fact that for size l(>=1), there will be central
# tick of length (l-1) then stick of length l, again central stick of (l-1) size

def draw_line(tick_length, tick_label = ''):
    line = '-'*tick_length
    # '' works as False in if - else setup
    if tick_label:
        line += tick_label
    print(line)

# Very simple to understand, as basic fundamental is followed.
# Draw the pattern till length is > 0, then print the centre line. As the
# pattern is symmetric below too, repeat the pattern.
def draw_interval(centre_length):
    if centre_length > 0:
        draw_interval(centre_length - 1)
        draw_line(centre_length)
        draw_interval(centre_length - 1)
# ^^ It's more like :: return (pattern + [centre_length] + pattern)
# Base case here is, n=0 nothing is printed.


def draw_ruler():
    major_length = int(input())
    num_inches = int(input())
    # Print the first line.
    draw_line(major_length, '0')
    # Print the repeates pattern till number of inches are covered.
    for j in range(1, 1 + num_inches):
        draw_interval(major_length - 1)
        draw_line(major_length, str(j))

draw_ruler()

'''
I am avoiding recursion for every inch, as it nothing but repetition of the
pattern above.
Moreover as the pattern is in integral form, it can be reused for other patterns.
'''
