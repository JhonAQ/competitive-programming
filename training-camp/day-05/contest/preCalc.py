import math

def calcSteps(a):
    return ceil(math.log(1000)/log(a-1/a))

def bestFor(a):
    if(a == 1):
        return 1000 + (2 / 1000)
    return bestFor(a - 1) * (1 + (2 / a))

for i in range(1, 1000):
    if bestFor(i) <= 18000:
        print("Best for:", i, "->", bestFor(i));
