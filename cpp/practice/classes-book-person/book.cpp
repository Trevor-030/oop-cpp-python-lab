#include <iostream>
#include <string>

using namespace std;

class Book {
    public:
        string title;
        string author;

        Book (string t, string a){
            title = t;
            author = a;
        }
        
        void display() {
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
        }

};


int main() {
    Book book1("Atomic Habits", "James Clear");
    book1.display();
    return 0;
}