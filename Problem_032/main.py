import math
def isPan(a, b):
    c = a * b
    matchArr = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    tp = [0] * 10
    sza = int(math.log10(a) + 1)
    szb = int(math.log10(b) + 1)
    szc = int(math.log10(c) + 1)
    for i in range (0, sza):
        tp[a % 10] += 1
        a //= 10
    for i in range (0, szb):
        tp[b % 10] += 1
        b //= 10
    for i in range (0, szc):
        tp[c % 10] += 1
        c //= 10
    good = True
    for i in range (0, 10):
        if (tp[i] != matchArr[i]):
            good = False
            break
    return good
s = 0
a = []
for i in range(1, 10000):
    for j in range(1, 1000):
        if (int(math.log10(i)) + int(math.log10(j)) + int(math.log10(i * j)) + 3 == 9 and isPan(i, j)): a.append(i * j)
a.sort()
for i in range(len(a) - 1, 0, -1):
    if (a[i] == a[i - 1]): del a[i]
for i in range(0, len(a)): s += a[i]
print(s)
