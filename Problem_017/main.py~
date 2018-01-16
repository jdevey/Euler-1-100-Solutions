import math

BIGNUM = 1000

answer = 0

for i in range (1, BIGNUM):
    num = i
    temp = answer
    firstTwoDigits = i % 100
    num = num // 100
    if (firstTwoDigits < 20 and firstTwoDigits > 9):
        if (firstTwoDigits == 10): answer += 3 #ten
        if (firstTwoDigits == 11): answer += 6 #eleven
        if (firstTwoDigits == 12): answer += 6 #twelve
        if (firstTwoDigits == 13): answer += 8 #thirteen
        if (firstTwoDigits == 14): answer += 8 #fourteen
        if (firstTwoDigits == 15): answer += 7 #fifteen
        if (firstTwoDigits == 16): answer += 7 #sixteen
        if (firstTwoDigits == 17): answer += 9 #seventeen
        if (firstTwoDigits == 18): answer += 8 #eighteen
        if (firstTwoDigits == 19): answer += 8 #nineteen

    else:
        firstDig = firstTwoDigits % 10
        secDig = firstTwoDigits // 10
        
        if (firstDig == 1): answer += 3 #one
        if (firstDig == 2): answer += 3 #two
        if (firstDig == 3): answer += 5 #three
        if (firstDig == 4): answer += 4 #four
        if (firstDig == 5): answer += 4 #five
        if (firstDig == 6): answer += 3 #six
        if (firstDig == 7): answer += 5 #seven
        if (firstDig == 8): answer += 5 #eight
        if (firstDig == 9): answer += 4 #nine

        if (secDig == 2): answer += 6 #twenty
        if (secDig == 3): answer += 6 #thirty
        if (secDig == 4): answer += 5 #forty
        if (secDig == 5): answer += 5 #fifty
        if (secDig == 6): answer += 5 #sixty
        if (secDig == 7): answer += 7 #seventy
        if (secDig == 8): answer += 6 #eighty
        if (secDig == 9): answer += 6 #ninety
        
    #counting up hundreds
    if (num > 0):
        if (i % 100 != 0): answer += 10 #because of "hundred and"
        else: answer += 7 #because of "hundred"

        if (num == 1): answer += 3 #one
        if (num == 2): answer += 3 #two
        if (num == 3): answer += 5 #three
        if (num == 4): answer += 4 #four
        if (num == 5): answer += 4 #five
        if (num == 6): answer += 3 #six
        if (num == 7): answer += 5 #seven
        if (num == 8): answer += 5 #eight
        if (num == 9): answer += 4 #nine

    print ("The number", i ,"had", answer - temp ,"letters")
    if (i % 10 == 0): print ("")
    if (i % 100 == 0): print ("\n")

answer += 11 #because of one thousand

print("The answer is:\n", answer)
