#include <iostream>
#include <cmath>

using namespace std;

class SimpleInterest {
    private:
        double principal, time, rate, interest;

    public:
        void input() {
            cout << "Enter Principal: ";
            cin >> principal;

            cout << "Enter Rate(%): ";
            cin >> rate;

            cout << "Enter Time(years): ";
            cin >> time;
        }

        void calculate() {
            interest = (principal * rate * time) / 100;
        } 


        void display() {
            cout << "Simple Interest = " << interest << endl;
        }
};

int main() {
    SimpleInterest si;
    si.input();
    si.calculate();
    si.display();
}