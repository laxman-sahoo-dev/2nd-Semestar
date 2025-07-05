#include<stdio.h>
#include <stdlib.h>
void move(int n ,char a ,char b ,char c)
{
    if(n>0){
        move(n-1,a,c,b);
        printf("%d Disk move Here %c to %c \n",n,a,c);
        move(n-1,b,a,c);
    }
}
int main()
{
    int n=3;
    char or='o',in='i',di='d';
    move(n,or,in,di);
}