#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a)
    {
        name = n;
        age = a;
        cout << "Constructor called." << endl;
    }

    // Copy Constructor
    Person(Person &other)
    {
        name = other.name;
        age = other.age;
        cout << "Copy Constructor called." << endl;
    }

    // Display function
    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    // Create an object
    Person p1("John", 30);
    p1.display();

    // Use the copy constructor
    Person p2(p1);
    p2.display();
} 