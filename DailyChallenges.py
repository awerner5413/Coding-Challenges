# Question:
# Define a class, which have a class parameter and have a same instance parameter.
# Hints:
# Define an instance parameter, need add it in __init__ method.You can init an object with 
# construct parameter or set the value later

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