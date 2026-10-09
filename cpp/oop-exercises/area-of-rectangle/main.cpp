#include <iostream>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    void getInput() {
        cout << "Enter Length: ";
        cin >> length;

        cout << "Enter Width: ";
        cin >> width;
    }

    double calculateArea() {
        return length * width;
    }


    void display() {
        cout << "\n****Area of a Rectangle****" << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << calculateArea() << endl;
    }
};

int main() {
    Rectangle r;

    r.getInput();
    r.display();

    return 0;
} 