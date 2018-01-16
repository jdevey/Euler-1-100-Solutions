import math

big = 10000

def findPrimes(n):
    if (n == 1): return 0
    if (n == 2): return 1
    if (n == 3): return 1

    sqt = math.sqrt(n)
    sum1 = 1

    for i in range (2, int(sqt) + 1):
        if (n % i == 0):
            sum1 += i
            if (i * i != n): sum1 += n // i

    return sum1

d = [None] * big
pairs = []

for i in range (1, big + 1):
    divSum = findPrimes(i)
    print(i,":" ,divSum)
    d[i - 1] = divSum

print("")

for i in range (0, big):
    for j in range (i + 1, big):
        if (i + 1 == d[j] and j + 1 == d[i]):
            pairs.append(d[i])
            pairs.append(d[j])
            print(i + 1,"" ,d[i])

print("")

sum1 = 0
for i in range (0, len(pairs)):
    sum1 += pairs[i]

print (sum1)
