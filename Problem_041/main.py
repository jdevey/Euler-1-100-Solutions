import math
BIG = 1000000000
def isPan(n):
    sz = int(math.log10(n)) + 1
    tp = [0] * (sz + 1)
    ex = [0]
    for i in range (0, sz): ex.append(1)
    while (n != 0):
        tp[n % 10] += 1
        n //= 10
    for i in range (0, len(tp)):
        if (tp[i] != ex[i]): return False
    return True
def isPrime(n):
    if (n < 2): return False
    if (n == 2 or n == 3): return True
    sqt = int(math.sqrt(n))
    for i in range (2, sqt + 1):
        if (n % i == 0): return False
    return True

a = [False]*BIG

a[0] = True
a[1] = True
for i in range (2, int(math.sqrt(BIG))):
    ind = 2 * i
    if (not isPrime(i)): a[i] = True
    while (ind < BIG):
        a[ind] = True
        ind += i
mx = 0
for i in range (100, BIG):
    if (not a[i] and isPan(i) and i > mx): mx = i
print(mx)
