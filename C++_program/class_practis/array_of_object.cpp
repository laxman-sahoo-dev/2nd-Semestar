#include <iostream>
using namespace std;
#include <string>
class Student {
private:
    string name;
    int roll;

public:
    void getData() {
        cout << "Enter name: ";
        getchar();
        getline(cin,name);
        cout << "Enter roll number: ";
        cin >> roll;
    }

    void displayData() {
        cout << "Name: " << name << ", Roll: " << roll << endl;
    }
};

int main() {
    Student s[3];  // Array of 3 Student objects

    for (int i = 0; i < 3; i++) {
        cout << "Enter details for student " << i + 1 << endl;
        s[i].getData();
    }

    cout << "\nDisplaying student information:\n";
    for (int i = 0; i < 3; i++) {
        s[i].displayData();
    }

    return 0;
}
