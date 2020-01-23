def fact(n):
    if(n==1):
        return 1
    else:
        return n*fact(n-1)
g = int(input())
# print(g)
i = 0
while(i<g):
    m = int(input())
    print(fact(m))
    i=i+1
