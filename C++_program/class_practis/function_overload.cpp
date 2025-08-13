#include <iostream>
using namespace std;
void fun(int x)
{
    cout<<"It is a integer"<<endl;
}
void fun(float f)
{
    cout<<"It is a float number"<<endl;
}
int  main()
{
    fun(3);
}