# quadratic.py

import math

class Quadratic:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def calculate(self):
        d = self.b**2 - 4*self.a*self.c

        if d > 0:
            root1 = (-self.b + math.sqrt(d)) / (2 * self.a)
            root2 = (-self.b - math.sqrt(d)) / (2 * self.a)
            print("Roots are Real and Distinct")
            print("Root 1 =", root1)
            print("Root 2 =", root2)

        elif d == 0:
            root = -self.b / (2 * self.a)
            print("Roots are Real and Equal")
            print("Root =", root)

        else:
            real = -self.b / (2 * self.a)
            imaginary = math.sqrt(-d) / (2 * self.a)
            print("Roots are Complex")
            print("Root 1 =", real, "+", imaginary, "i")
            print("Root 2 =", real, "-", imaginary, "i")