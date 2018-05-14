sm = 0
for i in range(0, 1000):
    num, den = 1, 2
    for j in range(i):
        num += 2 * den
        num, den = den, num
    num += den
    sm += len(str(num)) > len(str(den))
print(sm)
