# matrix.py

class Matrix:
    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
        self.matrix = []

    def input_matrix(self):
        print("Enter matrix elements:")
        for i in range(self.rows):
            row = []
            for j in range(self.columns):
                value = int(input(f"Element [{i}][{j}]: "))
                row.append(value)
            self.matrix.append(row)

    def display_matrix(self):
        for row in self.matrix:
            print(row)