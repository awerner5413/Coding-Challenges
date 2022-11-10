# Question:
# Define a class, which have a class parameter and have a same instance parameter.

class Pizza:
    """
        Pizza options:
        Sizes - small, medium, large
        Toppings - cheese or anyhting else
    """
    def __init__(self, size, topping):
        self.size = size
        self.topping = topping
    
    def cost(self):
        p = 0
        if self.size == "small":
            p += 7.50
        elif self.size == "medium":
            p += 9
        elif self.size == "large":
            p += 10.50
        if self.topping != "cheese":
            p += 1
        a = (f"Your pizza will cost ${p}")
        return a

alexOrder = Pizza('medium', 'cheese')
print(alexOrder.cost())


# Question:
# Define a function which can compute the sum of two numbers.

def adder(x, y):
    return x + y

print(adder(1,2))


# Question:
# Define a function that can convert a integer into a string and print it in console.

def stringConverter(number):
    string = str(number)
    print(string)
    return string

stringConverter(23)
print(type(stringConverter(23)))


# Question:
# Define a function that can receive two integer numbers in string form and compute their sum and then print it in console.

def sumStrings(x, y):
    a = int(x) + int(y)
    print(a)
    return a

x = input("Enter a number: ")
y = input("Enter another number: ")

print(type(sumStrings(x, y)))


# Question:
# Define a function that can accept two strings as input and concatenate them and then print it in console.

def combineStrings(x, y):
    print("Hi,", x + y)

x = input("What is your first name? ")
y = input("What is your last name? ")

combineStrings(x, y)


# Question:
# Define a function that can accept two strings as input and print the string with maximum length in console. If two strings have the same length, then the function should print all strings line by line.

def longestString(x, y):
    if len(x) > len(y):
        print(f"The longest string is: {x}")
    elif len(x) < len(y):
        print(f"The longest string is: {y}")
    else:
        print("Strings are the same length!")
        print(x)
        print(y)

x = input("Enter a string: ")
y = input ("Enter another: ")

longestString(x, y)