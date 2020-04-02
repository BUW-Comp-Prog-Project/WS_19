# prices_a = [8.70, 8.91,]
def factorial():
    f = list()
    start = 1
    for i in range(1,101):
        start*=i
        f.append(start)
    return f

fac = factorial()
t = int(input())
for i in range(t):
    n = int(input())
    print(fac[n-1])
