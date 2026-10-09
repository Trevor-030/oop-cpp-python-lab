# main.py

from temperature import Temperature

fahrenheit = float(input("Enter temperature in Fahrenheit: "))

temp = Temperature(fahrenheit)

print("Temperature in Centigrade =", temp.to_centigrade())