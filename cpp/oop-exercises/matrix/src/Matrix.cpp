#include "Matrix.h"
#include <iostream>

using namespace std;
int row;
int column;

Matrix::Matrix()
{
    //ctor

}
void Matrix::input()
{

    cout << "Enter number for row size: ";
    cin >> row;
    cout << "Enter number for column size: ";
    cin >> column;
    cout << "Elements of Matrix";
    for (int i=0;i<row;i++) {
        for (int j=0;j<column;j++){
            cout << "Number [" << i << "][" << j << "]=";
            cin >> number[i][j];
        }
    }
}

void Matrix::display() {
    cout <<endl<< "Elements of Matrix\n";
    for (int i=0;i<row;i++) {
        for (int j=0;j<column;j++) {
            cout << number[i][j] << " ";
        }

        cout << endl;
    }
}
