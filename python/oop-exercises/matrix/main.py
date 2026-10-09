# main.py

from matrix import Matrix

rows = int(input("Enter number of rows: "))
columns = int(input("Enter number of columns: "))

m = Matrix(rows, columns)

m.input_matrix()

print("Matrix:")
m.display_matrix()