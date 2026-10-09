class Matrix:

    def __init__(self):

        # Create an empty list to hold the rows
        self.number = []

        # Create a 2 × 2 matrix filled with zeros
        for i in range(2):

            row = []

            for j in range(2):
                row.append(0)

            self.number.append(row)

        self.row = 0
        self.column = 0


    def input(self):

        self.row = int(input("Enter number for row size: "))
        self.column = int(input("Enter number for column size: "))

        print("Elements of Matrix")

        for i in range(self.row):
            for j in range(self.column):
                self.number[i][j] = int(input(f"Number [{i}][{j}] = "))


    def display(self):

        print("\nElements of Matrix")

        for i in range(self.row):
            for j in range(self.column):
                print(self.number[i][j], end=" ")

            print()