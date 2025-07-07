#include <iostream>
using namespace std;
class parent
{
public:
    void parent_fun()
    {
        cout << "This is parent class" << endl;
    }
};

class child : public parent
{
public:
    void parent_fun()
    {
        cout << "This is child class" << endl; // Function overriding
    }
};

int main()
{
    child c1;
    parent p1;
    p1.parent_fun();
    c1.parent_fun();          // showding of base class function
    c1.parent ::parent_fun(); // Removing the showding
}