#include <stdio.h>
#include <stdlib.h>
char stack[10];
int top=-1;
void push(char ch)
{
    if(top==9)
    {
        printf("Stack is overflow");
        return;
    }
    top++;
    stack[top]=ch;
}
char pop()
{
    if(top==-1)
    {
        printf("stack is underflow");
        return;
    }
    return(stack[top--]);
}
char presedense(char ch )
{
    switch(ch)
    {
        case '^':
            if(stack[top]=='-'||stack[top]=='+'||stack[top]=='*'||stack[top]=='/')
            {
                push('^');
            }
        case '*':
            if(stack[top]=='-'||stack[top]=='+')
            {
                push('*');
            }
        
    }
}
 void create(char ch ,char *arr)
 {
    printf("Enter the character to push- \n");
    top++;
    scanf("%d",&arr[top]);
 }
void infinix_to_postfix(char *ptr1 ,char *ptr2)
{
    int i=0,j=0;
    while(*ptr1!='\0'){
        if(*(ptr1+i)!='*'||*(ptr1+i)!='^'||*(ptr1+i)!='+'||*(ptr1+i)!='-'||*(ptr1+i)!='/')
        {
            *(ptr2+j)=*(ptr1+i);
            i++;
            j++;
        }
        else if(*ptr1==')')
        {
            while(stack[top]!='(')
            {
                *(ptr2+j)=pop();
                j++;
            }
        }
        else
        {  
            while(stack[top]!=-1 && presedense(ptr1[j]))
            {
                
            }
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
    //char arr[y];
    printf("Enter the infinix form - ");

}