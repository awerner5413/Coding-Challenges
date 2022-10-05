# # ADD CS50 PROBLEMS TO CODING CHALLENGES - GET CREDIT FOR THAT C KNOWLEDGE

# Question:
# A robot moves in a plane starting from the original point (0,0). The robot can move toward UP, DOWN, LEFT and 
# RIGHT with a given steps. The trace of robot movement is shown as the following:
# UP 5
# DOWN 3
# LEFT 3
# RIGHT 2
# The numbers after the direction are steps. Please write a program to compute the distance from current position 
# after a sequence of movement and original point. If the distance is a float, then just print the nearest integer. 
# Example: If the following tuples are given as input to the program:
# UP 5
# DOWN 3
# LEFT 3
# RIGHT 2
# Then, the output of the program should be:
# 2

# need to change the directional strings into 0's for the tuple and change the number to an int
# need to determine which numbers will be negative (up adds to the value, down subtracts)
# add equation a^2 + b^2 = c^2 to determine the distance, set as int (solving for c - up/down is a and left/right is b)

import math
directions = []

while True:
    direction = input().split(' ')
    
    # Breaks for a blank input
    if not direction[0]:
        break
    directions.append(direction)

a = 0
b = 0
for d in directions:
    counter = 0
    for i in d:
        if counter == 0:
            v1 = i
            counter += 1
        elif counter == 1:
            v2 = int(i)
    if v1 == "UP":
        a += v2
    elif v1 == "DOWN":
        a -= v2
    elif v1 == "LEFT":
        b += v2
    elif v1 == "RIGHT":
        b -= v2 

c = int(math.sqrt(pow(a,2) + pow(b,2)))

print(c)