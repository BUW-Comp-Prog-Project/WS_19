def tautogram(X):
    X = [word for word in X.split()]
    temp = set(x[0] for x in X)
    if (len(temp) > 1):
        return False
    else:
        return True

while(2>1):
    X = input()
    if (X=='*'):
        break
    X = X.lower()
    if (tautogram(X)):
        print("Y")
    else:
        print("N")