# simple_interest.py

class SimpleInterest:
    def __init__(self, principal, rate, time):
        self.principal = principal
        self.rate = rate
        self.time = time

    def calculate_interest(self):
        return (self.principal * self.rate * self.time) / 100