BIG = 3000000 #Can't exceed 7 * 9! as the number itself surpasses even the largest factorial
factorial = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
s = 0
for i in range (10, BIG):
    c = i
    ss = 0
    while (c != 0):
        ss += factorial[c % 10]
        c //= 10
    if (ss == i): s += i
print(s)
