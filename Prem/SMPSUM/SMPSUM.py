# https://www.spoj.com/problems/SMPSUM/
x, y = input().split()
x = int(x)
y = int(y)
temp = x
add= 0
while(temp<=y):
    add += (temp*temp)
    temp=temp+1
print(add)