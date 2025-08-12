a = input()
b = input()
c = input()

actual = 'a'

while True:
    if actual == 'a': 
        if len(a) == 0:
            print('A')
            break
        actual = a[0]
        a = a[1:]
    elif actual == 'b': 
        if len(b) == 0:
            print('B')
            break
        actual = b[0]
        b = b[1:]
    elif actual == 'c': 
        if len(c) == 0:
            print('C')
            break
        actual = c[0]
        c = c[1:]
