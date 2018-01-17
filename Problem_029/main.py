import math
BIG = 100
a = []
for i in range (2, BIG + 1):
    for j in range (2, BIG + 1):
        a.append(i**j)
a.sort()
for i in range (len(a) - 1, 0, -1):
    if (a[i] == a[i - 1]): del a[i]
print(len(a))
