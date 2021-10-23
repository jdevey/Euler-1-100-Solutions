cache = {}

def pentagonal(n):
    return (3 * n * n - n) / 2

def p(n):
    if n == 0:
        return 1
    ans = 0
    i = 1
    while n - pentagonal(i) >= 0:
        previous = n - pentagonal(i)
        if previous not in cache:
            addition = p(n - i)
            cache[n - i] = addition
            ans += addition * (1 if i % 2 == 1 else -1)
        else:
            ans += cache[previous] * (1 if i % 2 == 1 else -1)
        i = (-i if i > 0 else -(i - 1))
    return ans;

num = 1
while True:
    partition = p(num)
    if partition % 1000000 == 0:
        print(num, p(num))
        break
    num += 1

