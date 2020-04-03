# https://www.spoj.com/problems/FUNPROB/
x,y = input().split()
x = int(x)
y= int(y)
while(x!=0 or y!=0):
    if(x>y):
        temp=0
        print("%.6f" % temp)
    else:
        temp = (y-x+1)/(y+1)
        print("%.6f" % temp)
    x, y = input().split()
    x= int(x)
    y=int(y)