import math

def calcSteps(a):
    base = a - 1/a
    if base <= 0:
        return float('inf')
    return math.ceil(math.log(1000) / math.log(base))

def bestFor(steps, a):
    return 1000 * ((1 + (2 / a)) ** steps)

for i in range(2, 40):
    steps = calcSteps(i)
    result = bestFor(steps, i)
    print("Best for:", i, "->", result)
