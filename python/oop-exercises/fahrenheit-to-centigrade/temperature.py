# temperature.py

class Temperature:
    def __init__(self, fahrenheit):
        self.fahrenheit = fahrenheit

    def to_centigrade(self):
        return (self.fahrenheit - 32) * 5 / 9