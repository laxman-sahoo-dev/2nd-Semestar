#include <iostream>
using namespace std;
class sample{
    private:
        int x;
        friend void display(sample);
    public:
        void getdata();
};
void sample::getdata()
{
    cout<<"Enter the value for x = ";
    cin>>x;
}
void display(sample abc)
{
    cout<<"Entered number is : "<<abc.x;
}
int main()
{
    sample obj;
    obj.getdata();
    cout<<"Accessing the private data by non-member function : \n "<<endl;
    display(obj);
    return 0;
}
