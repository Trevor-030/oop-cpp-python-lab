# main.py

from simple_interest import SimpleInterest

principal = float(input("Enter Principal: "))
rate = float(input("Enter Rate: "))
time = float(input("Enter Time: "))

si = SimpleInterest(principal, rate, time)

print("Simple Interest =", si.calculate_interest())