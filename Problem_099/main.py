import math
from functools import reduce
print(max(enumerate(map(lambda line: reduce(lambda a, b: math.log(int(a)) * int(b), line.split(',')), open('p099_base_exp.txt').readlines())), key=lambda x: x[1])[0] + 1)
