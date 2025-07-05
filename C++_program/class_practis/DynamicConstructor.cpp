#include <iostream>
#include <string>
using namespace std;
class abc
{
private:
    string name;
    int roll;

public:
    void get_data()
    {
        cout << "Enter Name- ";
        cin >> name;
        cout << "Enter Roll_No.- ";
        cin >> roll;
    }
    void display_data()
    {
        cout << name << endl;
        cout << roll << endl;
    }
};
int main()
{
    abc *obj = new abc();
    cout<<obj<<endl;
    obj->get_data();
    obj->display_data();
    abc *obj1 =new abc();
    cout<<obj1<<endl;
    (*obj1).get_data();
    (*obj1).display_data();
    delete obj1;
    delete obj;
    cout<<obj1<<endl;
    cout<<obj<<endl;
}
