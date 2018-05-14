exp, cnt = 1, 0;
while(True):
    base, ic = 1, 0
    while (len(str(base**exp)) <= exp):
        if (exp == len(str(base**exp))):
            ic += 1
        base += 1
    if (ic == 0): break
    cnt += ic
    exp += 1
print(cnt)
