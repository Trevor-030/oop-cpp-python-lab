# fibonacci.py

class Fibonacci:
    def __init__(self, n):
        self.n = n

    def display(self):
        first = 0
        second = 1

        for i in range(self.n):
            print(first)
            next_number = first + second
            first = second
            second = next_number

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         