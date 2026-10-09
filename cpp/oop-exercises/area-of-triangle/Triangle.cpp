#include <iostream>
#include "Triangle.h"

using namespace std;

void Triangle::getInput() {
    cout << "Enter Base: ";
    cin >> base;

    cout << "Enter Height: ";
    cin >> height;
}

double Triangle::calculateArea() {
    return 0.5 * base * height;
}

void Triangle::display() {
    cout << "\n****Area of a Triangle****" << endl;
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
    cout << "Area: " << calculateArea() << endl;
}

// Michael Agyenim Boateng Anning
// SRI.41.008.026.25