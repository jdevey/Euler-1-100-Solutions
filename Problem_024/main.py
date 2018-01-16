big = 1000000
a = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
#a = [3, 2, 1, 0]

pCount = 0
ansArr = []
sz = len(a)

fac = 1
for i in range (2, sz + 1): fac *= i

twoD = []
def arrApp():
    s = ""
    for i in range (0, sz):
        s += chr(a[i] + 48)
    twoD.append(s)
    #print(s)

def printArr():
    for i in range (0, sz):
        print(a[i], end = '')
    print("")

def arrCopy(arr = []):
    arc = []
    for i in range (0, sz):
        t1 = arr[i]
        arc.append(t1)
    for i in range (0, sz):
        ansArr.append(arc)

c = [0] * sz

#HEAP'S ALGORITHM
z = 0
while z < sz:
    if (c[z] < z):
        arrApp()
        #printArr()
        if (not (z & 1)):
            pCount += 1
            if (pCount == big): arrCopy(a)
            temp = a[0]
            a[0] = a[z]
            a[z] = temp
        else:
            pCount += 1
            if (pCount == big): arrCopy(a)
            temp = a[c[z]]
            a[c[z]] = a[z]
            a[z] = temp
        c[z] += 1
        z = 0
    else:
        c[z] = 0
        z += 1

arrApp()

#print (a[0],a[1],a[2],a[3])

#arrApp()
'''
for i in range (0, len(twoD)):
    print(twoD[i])
'''
#for i in range (0, sz): print(ansArr[i])

#print ("\nPost-sort...\n")

twoD.sort(key = str.lower)
'''
for i in range (0, len(twoD)):
    print(twoD[i])
'''
#the answer
print ("\n",twoD[big - 1])
