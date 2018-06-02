import math

vvp = []

def isSquare(n):
    sqt = int(math.sqrt(n))
    return sqt * sqt == n or (sqt + 1) * (sqt + 1) == n

def euclidean(n, m):
    return n if m == 0 else euclidean(m, n % m)

def seqGen():
    vvp.append([])
    for i in range(1, 1001):
        if (isSquare(i)):
            vvp.append([])
            continue
        a, b, d = 1, int(math.sqrt(i)), 1
        sp = set([(1, b, 1)])
        vp = [b]
        while (True):
            newA = d * a
            newB = d * b
            newD = a * a * i - b * b
            gcd = euclidean(newD, d)
            newA //= gcd
            newB //= gcd
            newD //= gcd
            seq = int((newA * math.sqrt(i) + newB) / newD)
            vp.append(seq)
            newB -= newD * seq
            newB = math.fabs(newB)
            a = newA
            b = newB
            d = newD
            if ((a, b, d) in sp):
                vvp.append(vp)
                break
            sp.add((a, b, d))

def genFrac(vp, depth):
    vcop = list(vp)
    lst = []
    lst.append(vcop[0])
    vcop.pop(0)
    for i in range(0, depth - 1):
        lst.append(vcop[i % len(vcop)])
    n, d = 1, 0
    for i in reversed(lst):
        t = i * n + d
        d = n
        n = t
    return (n, d)

seqGen()

ans = []
for i in range(1, 1001):
    if (isSquare(i)):
        continue
    j = 1
    while(True):
        frac = genFrac(vvp[i], j)
        if (frac[1] * frac[1] * i + 1 == frac[0] * frac[0]):
            ans.append((frac[0] * frac[0], i))
            break
        j += 1

ans.sort()

print(ans[-1][1])
