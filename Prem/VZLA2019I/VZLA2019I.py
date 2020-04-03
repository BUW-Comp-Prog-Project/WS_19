# https://www.spoj.com/problems/VZLA2019I/
n = input()
temp = [int(num) for num in n.split()]
# print(temp)
mul = 1
for num in temp:
    mul*=num
print(mul)