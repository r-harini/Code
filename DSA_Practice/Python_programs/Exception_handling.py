import math
import sys
lines=[]
try:
    while (True):
        
        line=input("Enter the sentence:")
        lines.append(line)
except SyntaxError:
    for i in range(len(lines)):
        print(lines[-1-i])
