# Question:
# Python has many built-in functions, and if you do not know how to use it, you can read document online or find some books.
# But Python has a built-in document function for every built-in functions.
# Please write a program to print some Python built-in functions documents, such as abs(), int(), raw_input()
# And add document for your own function
# Hints:
# The built-in document method is __doc__

def multBy10(num):
    """This program will take a given number and multiply it by 10"""
    a = num * 10
    return a

num = int(input("Give me a number: "))

print(multBy10(num))
print(abs.__doc__)
print(int.__doc__)
print(multBy10.__doc__)