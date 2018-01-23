import math

def isPrime(n):
    if (n < 2): return False
    if (n == 2 or n == 3): return True
    sqt = int(math.sqrt(n))
    for i in range (2, sqt + 1):
        if (n % i == 0): return False
    return True

a = [False]*1000000

def isGood(n):
    sz = int(math.log10(n))
    copy = n
    while (copy != 0):
        if (a[copy]): return False
        copy //= 10
    while (sz != 0):
        if (a[n]): return False
        n %= 10**(sz)
        sz -= 1
    if (a[n]): return False
    return True

a[0] = True
a[1] = True
for i in range (2, 1000):
    ind = 2 * i
    if (not isPrime(i)): a[i] = True
    while (ind < 1000000):
        a[ind] = True
        ind += i

tCount = 0
s = 0
for i in range (11, 1000000):
    if (isGood(i)):
        s += i
        tCount += 1
    if (tCount == 11): break

print(tCount, s)
