from cs50 import get_float


def main():
    c = get_cents()

    # calculate the amount of quarters
    q = c // .25
    c = round(c - q * .25, 2)

    # calculate the amount of dimes
    d = c // .1
    c = round(c - d * .1, 2)

    # calculate the amount of nickels
    n = c // .05
    c = round(c - n * .05, 2)

    # calculate the amount of pennies
    p = c // .01

    # sum the amound of coins and print the answer
    t = round(q + d + n + p)
    print(t)


# get the amount of change due by the user
def get_cents():
    while True:
        c = get_float("Change owed: ")
        if c > 0:
            break
    return c


main()