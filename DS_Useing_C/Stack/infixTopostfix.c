//infix to post fix
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
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
        exit(0);
    }
    return(stack[top--]);
}
int presedense(char ch )

{
    switch(ch)
    {
        case '^':
            return 4;
        case '*':
        case '/':
        case '%':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 1;
            break;
        default:
            return 0;
    }
}
void infinix_to_postfix(char *infix ,char*post)
{
    int i=0,p=0;
    char ch;
    while((ch=infix[i])!='\0')
    {   
        if(ch=='\n'||ch==' ')
        {
            i++;
            continue;
        }  
       if(isalnum(ch))
       {
             post[p]=ch;
             p++;
       }
       else if(ch=='(')
       {
            push(ch);
       }
       else if(ch==')')
       {
            while(top!=-1 && stack[top]!='(')
            {
                post[p]=pop();
                p++;
            }
            if(top!=-1 && stack[top]=='(')
            {
                pop();
            }
       }
       
       else
       {
        while (top!=-1 && presedense(ch) <= presedense(stack[top]))
        {
            post[p]=pop();
            p++;
            
        }
        push(ch);
       }
       i++;
    }
    while (top!=-1)
       {
        post[p++]=pop();
       }  
    post[p]='\0';
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str[30],post[30];
    printf("Enter the infinix form - ");
    fgets(str, sizeof(str), stdin);
    infinix_to_postfix(str,post);
    printf("postfix=%s",post);
}