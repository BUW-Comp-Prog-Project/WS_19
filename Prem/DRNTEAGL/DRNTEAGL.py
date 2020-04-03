# https://www.spoj.com/problems/DRNTEAGL/

n = int(input())
i=1
while(i<=n):
    p = int(input())
    big = 0
    counter = 0
    cases = counter
    while(p>0):
        p1, p2 = input().split()
        p1 = int(p1)
        p2 = int(p2)
        p1 = p1*p1
        p2 = p2*p2
        add = p1+p2
        counter +=1
        if(add>big):
            big=add
            cases = counter
        p = p-1
    print("Case "+ str(i)+ ": "+ str(cases))
    i=i+1