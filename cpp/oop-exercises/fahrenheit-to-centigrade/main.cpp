#include <iostream>

using namespace std;

class Temperature {
    private:
        double fahrenheit;
        double centigrade;


    public:
    void input() {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> fahrenheit;
    }

    void convert() {
        centigrade = (fahrenheit - 32) * 5/9;
    }

    void display() {
        cout << "Temperature in Centigrade: " << centigrade << " Degree Celsius" << endl;
    }
  
};

int main() {
    Temperature temp;
    temp.input();
    temp.convert();
    temp.display();
}