#include <stdio.h>
#include <stdlib.h>
#define max 30
#include <string.h>
#include <ctype.h>
typedef struct stack{
    char arr[max];
    int top;
}stack;
void init_stack(stack *st)
{
    st->top=-1;
}
void push_stack(stack *st,int ch)
{
    if(st->top==max-1)
    {
        printf("Stack is full");
        exit(0);
    }
    st->arr[++st->top]=ch;
}
char pop_stack(stack *st)
{
    if(st->top==-1)
    {
        printf("Stack is empty");
        return '\0';
    }
    else
    {
        return st->arr[st->top--];
    }
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

void infix_to_prefix(stack *st, char *in,char *pre)
{
    int i=0,j=0;
    char ch;
    init_stack(st);
    while (in[i]!='\0')
    {
        ch=in[i];
        if(ch==' ' || ch =='\n')
        {
            i++;
            continue;
        }
        if(isalnum(ch))
        {
            pre[j]=ch;
            j++;
        }
        else if(ch=='(')
        {
            push_stack(st,ch);
        }
        else if (ch==')')
        {
            while(st->top!=-1 && st->arr[st->top]!='(')
            {
                pre[j]=pop_stack(st);
                j++;
            }
            if(st->arr[st->top]=='(')
            pop_stack(st);
        }
        else
        {
            while(st->top!=-1 && presedense(ch) < presedense(st->arr[st->top]))
            {
                pre[j++]=pop_stack(st);
            }
            push_stack(st,ch);
        }
        i++;     
    }
    while (st->top!=-1)
    {
        pre[j++]=pop_stack(st);
    }
    pre[j]='\0'; 
}
int main()
{
    char infix[max],rinfix[max],prefix[max],rprefix[max];
    stack st;
    init_stack(&st);
    printf("Enter a string-");
    fgets(infix,sizeof(infix),stdin);
    if(infix[strlen(infix)-1]=='\n'){
        infix[strlen(infix)-1]='\0';
    }
    int j=strlen(infix)-1,i=0;
    while(j!=-1){
        if(infix[j]=='(')
            rinfix[i++]=')';
        else if(infix[j]==')')
            rinfix[i++]='(';
        else
        {
            rinfix[i++]=infix[j];
        }
        j--;
    }
    rinfix[i]='\0';
    printf("%s\n",rinfix);
    printf("%d\n",strlen(rinfix));
    infix_to_prefix(&st,rinfix,prefix);
    j=strlen(prefix)-1;
    i=0;
    while (j!=-1)
    {
        rprefix[i++]=prefix[j];
        j--;
    }
    
    printf("\n%s",rprefix);
}
