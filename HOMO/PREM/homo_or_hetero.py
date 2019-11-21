z = int(input())
# print('neither')
# print(z)
dict = {}
    # print('hey')
homo = 0
hetero = 0
while(z>0):
    op, num = input().split()
    num = int(num)
    print(op,num)

    if (op =='insert'):
        if num in dict:
            # Check if the element is in the dictionary or not
            dict[num]+=1
            homo +=1
            if(len(dict)==1):
                # decrease the count of hetero when dict has only one lement
                hetero = 0
                # homo = 0
        else:
            dict[num] = 1
            if (len(dict)>1):
                hetero +=1

    # print(dict)
    # else perform the delete operation
    else:
        # print('done')
        if num in dict.keys():
            dict[num] -= 1
            if (dict[num] == 0):
                # after deleting the key in dictionary reduce the count of hetero by 1
                del dict[num]
                hetero -= 1
            elif (dict[num] == 1):
                # decrease the count of homo by 1 when only one of the particular key is left
                homo -= 1
            if (len(dict) == 1):
                m = list(dict.values())
                # print(type(z))
                if (m[0] > 1):
                    hetero -= 1



    # # we perform check homo or hetero
    # if (homo != 0 and hetero != 0):
    #     print('both')
    # elif (hetero==0 and homo!=0):
    #     print('homo')
    # elif( hetero !=0 and homo ==0):
    #     print('hetero')
    # else:
    #     print('neither')
    # print("hetero is " , hetero)
    # print("homo is ,", homo)


        # check_homo_hetero()
    z = z-1

# print('************************************************')
# for elemnt in dict:
#     print(elemnt,dict[elemnt])