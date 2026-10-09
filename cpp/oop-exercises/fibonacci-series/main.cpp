#include <iostream>

using namespace std;

class Fibonacci {
    private:
        int n;
    
    public:
        void setNumber(int num) {
            n = num;
        }

        void displaySeries() {
            int first = 0, second = 1, next;

            cout << "Fibonacci Series: ";


            for (int i = 0; i < n; i++) {
                cout << first << " ";

                next = first + second;
                first = second;
                second = next;

            cout << endl;
            }
        }
};

int main() {
    Fibonacci fib;

    int terms;
    cout << "Enter the number of terms: ";
    cin >> terms;

    fib.setNumber(terms);
    fib.displaySeries();

    return 0;
}