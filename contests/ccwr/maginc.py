t = int(input())
for j in range(t):
	x, k = map(int, input().split())
	dup = x
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	for i in range(k):
		x += x*(a[i]/b[i])
	ans = int(100 - (100*dup)/x)
	print(ans)

