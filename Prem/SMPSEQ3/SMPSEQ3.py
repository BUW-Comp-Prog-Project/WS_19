n = int(input())
temp = input()
s = [int(num) for num in temp.split()]
m = int(input())
temp = input()
q = set([int(num) for num in temp.split()])
z=[]
for elem in s:
    if elem not in q:
        z.append(elem)
print(*z, sep=" ")


#     s.append(temp)
#     n=n-1
# m = int(input())
# while(m>0):
#     temp = int(input())
#     q.append(temp)
#     m=m-1
# print(s)
# print(q)
