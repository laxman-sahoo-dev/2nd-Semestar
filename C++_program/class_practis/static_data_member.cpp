#include <iostream>
using namespace std;
class base
{
public:
    static int count;
    base()
    {
        count++;
    }
    void show()
    {
        cout<<"Count= "<<count<<endl; 
    }
};
int base::count=9;
int main()
{
    base obj1,obj2,obj3,obj4;
    obj1.show();
    obj3.show();
    
}
