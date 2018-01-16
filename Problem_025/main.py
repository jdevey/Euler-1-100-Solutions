import math

big = 1000

def numDig (n):
    return int(math.log10(n)) + 1

x = 2
oneBefore = 1
twoBefore = 1
index = 3

while (numDig(x) < big):
    x = x + oneBefore
    oneBefore = oneBefore + twoBefore
    twoBefore = oneBefore - twoBefore
    index += 1
    print ("index: ",index," - ",x)

print (index)
