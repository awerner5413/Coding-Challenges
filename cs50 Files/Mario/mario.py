from cs50 import get_int

# get the height of pyramid from user
while True:
    n = get_int("Height: ")
    if 0 < n < 9:
        break

# print the right-aligned pyramid
for j in range(n):
    print(" " * (n - j - 1), "#" * (j + 1), sep="", end="")
    print(" " * 2, end="")
    print("#" * (j + 1))