import math
sm = 0
def numDig(n):
    return len(str(n)) - 1
def isPal(n):
    s = str(n)
    for i in range(len(s)):
        if (s[i] != s[len(s) - i - 1]):
            return False
    return True
for i in range(1, 10000):
    prog = i
    for j in range(49):
        cpy = prog
        rev = 0
        while (cpy):
            rev += cpy % 10 * 10**numDig(cpy)
            cpy //= 10
        prog += rev
        if (isPal(prog)):
            break
        if (j == 48):
            sm += 1
print(sm)
