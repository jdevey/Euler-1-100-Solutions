BIG = 6*9**5
def isGood(nn):
    n = nn
    sm = 0
    while (not n == 0):
        sm += (n % 10)**5
        n //= 10
    return sm == nn
sm = 0
for i in range (10, BIG):
    if (isGood(i)): sm += i
print(sm)
