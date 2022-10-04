# Question:
# You are required to write a program to sort the (name, age, score) tuples by ascending order where name is string, age and score are numbers. The tuples are input by console. The sort criteria is:
#
# 1: Sort based on name
# 2: Then sort based on age
# 3: Then sort by score
# The priority is that name > age > score.
#
# If the following tuples are given as input to the program:
#
# Tom,19,80
# John,20,90
# Jony,17,91
# Jony,17,93
# Json,21,85
# Then, the output of the program should be:
#
# [('John', '20', '90'), ('Jony', '17', '91'), ('Jony', '17', '93'), ('Json', '21', '85'), ('Tom', '19', '80')]

import operator

data = []
x = 0

while x < 5:
    person = 0
    person = tuple(input("Enter the data: ").split(","))
    data.append(person)
    x += 1

score = operator.itemgetter(2)
age = operator.itemgetter(1)
name = operator.itemgetter(0)

data = sorted(data, key=score)
data = sorted(data, key=age)
data = sorted(data, key=name)

print(data)