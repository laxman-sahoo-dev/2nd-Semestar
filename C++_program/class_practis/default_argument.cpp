#include <iostream>
using namespace std;

void sum(int x =1,int y=1,int z=2,int p=3,int q=2)
{
    int sum;
    sum=x+y+z+p+q;
    cout<<"SUM= "<<sum<<endl;
}
int main()
{
    int a=5,b=6,d=5,c=1,e=3;
    sum(a,b);
    sum(a,b,c);
    sum(a);
    sum(d);
    sum(a,b,c,d,e);
}

