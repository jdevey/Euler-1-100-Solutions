import math

def is_square(n):
    return math.sqrt(n) == round(math.sqrt(n))

def bs(n):
    base = 0
    jump = int(2 ** (math.floor(math.log(n, 2))))
    while jump > 0:
        test = base + jump
        if test ** 2 < n:
            base += jump
        jump //= 2
    return base

def get_sum_of_first_100(n):
    zeros = 208
    expanded = n * 10 ** zeros
    sqrt = bs(expanded)
    sqrt_str = str(sqrt)
    s = 0
    cnt = 0
    for c in sqrt_str:
        s += ord(c) - ord('0')
        cnt += 1
        if (cnt == 100):
            break
    return s

total = 0
for i in range(100):
    if not is_square(i):
        total += get_sum_of_first_100(i)

print(total)

