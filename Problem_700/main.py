def ext(a, b, x, y):
    if b == 0:
        x[0] = 1
        y[0] = 0
        return
    ext(b, a % b, x, y)
    temp = x[0] - a // b * y[0]
    x[0] = y[0]
    y[0] = temp

def mod_inv(a, m):
    x = [0]
    y = [0]
    ext(a, m, x, y)
    return x[0] + m if x[0] < 0 else x[0]

def main():
    print("Phase one")
    a = 1504170715041707
    m = 4503599627370517
    mn = 1e100
    sm = 0
    cnt = 1
    while mn > 5e7:
        val = a * cnt % m
        if val < mn:
            mn = val
            sm += val
            print(mn)
        cnt += 1
    print("Phase two")
    b = mod_inv(a, m)
    found = []
    for i in range(1, mn):
        steps = b * i % m
        found.append((steps, i))
    found.sort()
    for f in found:
        if f[1] < mn:
            mn = f[1]
            sm += f[1]
            if (f[1] == 1):
                break
    print(sm)

main()
