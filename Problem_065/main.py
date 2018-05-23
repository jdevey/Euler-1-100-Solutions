seq = [2]
for i in range(2, 101):
    if (i % 3 == 0):
        seq.append(i // 3 * 2)
    else: seq.append(1)
n, d = 1, 0
for i in reversed(seq):
    t = i * n + d
    d = n
    n = t
print(sum(int(c) for c in str(n)))
