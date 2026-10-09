#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
        int age;

    public:
        void setName(string n) {
            name = n;
        }
        void setAge(int a) {
            age = a;
        }

        string getName() {
            return name;
        }

        int getAge() {
            return age;
        }

        void display() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};


int main() {
    Person person_1;
     
    person_1.setName("Michael");
    person_1.setAge(18);

    person_1.display();

    return 0;
}
