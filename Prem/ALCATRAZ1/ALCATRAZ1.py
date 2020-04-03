# https://www.spoj.com/problems/ALCATRAZ1/
n = int(input())
while(n>0):
    temp = input()
    add=0
    temp = [char for char in temp]
    for num in temp:
        add +=int(num)
    n=n-1
    print(add)