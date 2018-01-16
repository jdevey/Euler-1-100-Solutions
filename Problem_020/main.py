import math

sum1 = 0
rProd = 1
for i in range (1, 101):
    rProd *= i

for i in range (0, int(math.log10(rProd)) + 1):
    sum1 += rProd % 10
    rProd //= 10

print (sum1)
