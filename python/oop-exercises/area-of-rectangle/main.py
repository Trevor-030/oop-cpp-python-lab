# main.py

from rectangle import Rectangle


length = float(input("Enter the length: "))
width = float(input("Enter the width: "))

rectangle = Rectangle(length, width)

print("Area of the rectangle =", rectangle.calculate_area())