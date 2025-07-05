#include <iostream>
using namespace std;
class abc{
    public:
        abc();
        abc(int);
        abc(float);
        abc(int,float);
};
abc::abc()
{
    cout<<"Calling default constructor."<<endl;
}
abc::abc(int a)
{
    cout<<"calling constructor with integer"<<endl;
}
abc::abc(float fa)
{
    cout<<"calling constructor with floating point number"<<endl;

}
abc::abc(int a,float fa)
{
    cout<<"calling construct with foating point number & integer nunber"<<endl;
}
int main()
{
    abc obj;
    abc(10);
    abc(2,8.9);
    abc(7.9f);
}