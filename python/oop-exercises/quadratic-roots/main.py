# main.py

from quadratic import Quadratic

a = float(input("Enter a: "))
b = float(input("Enter b: "))
c = float(input("Enter c: "))

q = Quadratic(a, b, c)
q.calculate()