#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
//int main()
/*{   cout<<"Enter five number = ";
    int arr[5];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    int mx=INT_MAX;
    for(int i=0;i<5;i++)
    {
        mx=min(mx,arr[i]);
    }
    cout<<mx<<endl;
}*/
/*{
    cout << "Enter five number = ";
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    int max = arr[0];
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << max << endl;
}*/
/*{   
    string st;
    cout<<"Enter a Saring - ";
    getline(cin,st);
    cout<<st;
}*/

class Student {
private:
    string name;
    int roll;

public:
    void getData() {
        cout << "Enter name: ";
        cin >> name;
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
