#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
    string city;
    string profession;
};

void print(const Person *person) {
    cout << person->name << " is " << person->age
         << " years old, lives in " << person->city
         << " and works as " << person->profession << endl;
}

int main() {
    Person person;
    person.name = "Harry";
    person.age = 23;
    person.city = "London";
    person.profession = "teacher";

    Person person2;
    person2.name = "Anna";
    person2.age = 19;
    person2.city = "Kyiv";
    person2.profession = "student";

    Person person3;
    person3.name = "Mark";
    person3.age = 31;
    person3.city = "Lviv";
    person3.profession = "engineer";

    cout << "Meet " << person.name << endl;
    print(&person);
    print(&person2);
    print(&person3);

    return 0;
}
