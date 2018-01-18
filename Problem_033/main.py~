def isGood(a, b):
    x = 0
    y = 0
    if (a % 10 == b // 10):
        x = a // 10
        y = b % 10
    elif (a // 10 == b % 10):
        x = a % 10
        y = b // 10
    else: return False
    if (a / b == x / y): return True
    else: return False
a = []
b = []
for i in range (10, 99):
    for j in range (i + 1, 100):
        if (i % 10 != 0 and j % 10 != 0 and isGood(i, j)):
            a.append(i)
            b.append(j)
prod1 = 1
prod2 = 1
for i in range (0, len(a)):
    prod1 *= a[i]
    prod2 *= b[i]
print(prod1, prod2)
#Now divide the result to see it in lowest terms
