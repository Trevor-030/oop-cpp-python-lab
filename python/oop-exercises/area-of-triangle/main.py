# main.py

from triangle import Triangle

base = float(input("Enter the base: "))
height = float(input("Enter the height: "))

triangle = Triangle(base, height)

print("Area of the triangle =", triangle.calculate_area())