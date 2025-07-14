import math

def calcSteps(a):
    return math.ceil(math.log(1000)/math.log(a-1/a))

def bestFor(steps, a):
    if steps == 1:
        return 1000 * (1 + 2/a)
    return bestFor(steps - 1, a) * (1 + (2 / a))

for i in range(1, 1000):
    if bestFor(calcSteps(i), i) <= 18000:
        print("Best for:", i, "->", bestFor(calcSteps(i), i));
