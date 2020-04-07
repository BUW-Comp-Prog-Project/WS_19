def comp_seq(temp, y):
    for i in range(1, len(temp)):
        set_a = set(temp[:i])
        set_b = set(temp[i:])
        top_a = max(set_a)
        top_b = max(set_b)
        for i in range(1, top_a+1):
            if


    return 1
n = int(input())
while(n>0):
    x,y = input().split()
    x = int(x)
    y=int(y)
    temp = input()
    temp = [int(num) for num in temp.split()]
    # print(temp)
    num = comp_seq(temp, y)
    # print(num)
    n=n-1