import math

BIG = 1000000
a = [False] * BIG

def isPrime(n):
    for i in range (2, int(math.sqrt(n)) + 1):
        if (n % i == 0): return False
    return True

def isGood(n):
    numDig = int(math.log10(n) + 1)
    #print(n, numDig)
    for i in range (0, numDig):
        if (a[n]): return False
        c = n % 10
        n //= 10
        n += c * 10**(numDig - 1)
    return True

for i in range (2, int(math.sqrt(BIG))):
    if (not isPrime(i)): a[i] = True
    ind = i * 2
    while (ind < BIG):
        a[ind] = True
        ind += i

s = 13
for i in range (101, BIG):
    if (not a[i] and isGood(i)): s += 1
for i in range (0, 2000): print(i,":", 1 if a[i] else 0)

print(s)
