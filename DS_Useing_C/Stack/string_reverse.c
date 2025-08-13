#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20
typedef struct array{
    char arr[max];
    int top;
}instack;
void init(instack *st)
{
    st->top=-1;
}
void create_stack(instack *st,char ch)
{
    if(st->top==max-1)
    {
        printf("stack is full!!\n");
        return;
    }
    //st->top=st->top+1;
    st->arr[++st->top]=ch;
    printf("stack push successfully...\n");
    return;
}
char pop_stack(instack *st)
{   
    if(st->top==-1)
    {
        printf("Stack is empty!!");
        exit(1);
    }
    //st->top=st->top-1;
    return(st->arr[st->top--]);
}
int main()
{
    char str[max],ch;
    instack st;
    init(&st);
    int i=0;
    printf("Enter a sering- ");
    fgets(str,sizeof(str),stdin);
    if(str[strlen(str)-1]=='\n')
    {
        str[strlen(str)-1]='\0';
    }
    while(str[i]!='\0')
    {
        create_stack(&st,str[i]);
        i++;
    }
    i=0;
    printf("Display in reverse order-\n");
    while(str[i]!='\0')
    {
        ch=pop_stack(&st);
        printf("%c\n",ch);
        i++;
    }

}