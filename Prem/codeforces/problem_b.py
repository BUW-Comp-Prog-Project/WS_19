
def check_permut(set_a):
    top = max(set_a)
    flag = True
    for i in range(1, top+1):
        if i in set_a :
            flag = True
        else:
            flag = False
            break

    return flag


n = int(input())
while(n>0):
    counter = 0
    list_1 =[]
    list_2 =[]
    l = int(input())
    temp = input()
    temp = [int(num) for num in temp.split()]
    for i in range(1, len(temp)):
        set_a = set(temp[:i])
        set_b = set(temp[i:])
        if(len(set_a)==1 and len(set_b)==1):
            break
        a = check_permut(set_a)
        b = check_permut(set_b)
        # print(a, b)
        if(a==b and a == True):
            if(len(set_a)+len(set_b)==l):
                counter+=1
                a1 = len(set_a)
                a2 = len(set_b)
                list_1.append(a1)
                list_2.append(a2)
    print(counter)
    for x, y in zip(list_1, list_2):
        print(x, y)
    #     print(a1, a2)

    n=n-1