#include <iostream>
#include <cmath>

using namespace std;

class Quadratic {
private:
    double a, b, c;

public:
    void getInput() {
        cout << "Enter coefficient a: ";
        cin >> a;

        cout << "Enter coefficient b: ";
        cin >> b;

        cout << "Enter coefficient c: ";
        cin >> c;
    }

    void findRoots() {
        double discriminant, root1, root2;

        discriminant = (b * b) - (4 * a * c);

        if (discriminant > 0) {
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);

            cout << "Root 1 = " << root1 << endl;
            cout << "Root 2 = " << root2 << endl;
        }
        else if (discriminant == 0) {
            root1 = -b / (2 * a);

            cout << "Equal Roots = " << root1 << endl;
        }
        else {
            cout << "No Real Roots." << endl;
        }
    }
};

int main() {
    Quadratic q;

    q.getInput();
    q.findRoots();

    return 0;
}