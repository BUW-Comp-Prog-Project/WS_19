# https://www.spoj.com/problems/AVRG/
n = 6
temp = 0
add = 0
while(n>0):
    temp = float(input())
    add+=temp
    n=n-1
print(add/6)