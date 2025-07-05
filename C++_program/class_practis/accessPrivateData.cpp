#include <iostream>

using namespace std;
class sample{
    private:
        int x;
    public:
        sample();
        void display();
   //     void display();
};
sample::sample()
{
    cout<<"Enter the value for x = ";
    cin>>x;
}
void sample::display()
{
    cout<<"Entered number is : "<<x;
}
int main()
{
    sample obj;
    //obj.getdata();
    cout<<"Accessing the private data by non-member function : \n "<<endl;
    obj.display();
    return 0;
}
