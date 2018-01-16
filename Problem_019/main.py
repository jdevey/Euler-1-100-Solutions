import math

def isLeap (year):
    if (year % 400 == 0): return True
    if (year % 100 == 0): return False
    if (year % 4 == 0): return True
    return False

sundayCount = 0

# We'll let zero denote Sunday, 1 denote Monday, etc... up to 6, which denotes Saturday. January 1, 1901 was a Tuesday.
currDay = 2

for i in range (1901, 2001):
    for j in range (1, 13):
        dayCount = 0
        if (j == 1 or j == 3 or j == 5 or j == 7 or j == 8 or j == 10 or j == 12): dayCount = 31
        if (j == 4 or j == 6 or j == 9 or j == 11): dayCount = 30
        if (j == 2):
            if (isLeap(i)): dayCount = 29
            else: dayCount = 28

        if (currDay == 0): sundayCount += 1
        currDay += dayCount % 7
        currDay %= 7

print (sundayCount)
    
