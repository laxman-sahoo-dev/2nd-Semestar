#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodetype
{
    char ch;
    struct nodetype *next;
}node;

typedef struct stack{
    node *top;
}stack;

void init(stack *st)
{
    st->top=NULL;
}

void push_stack(stack *st,char ch)
{
    node *curr;
    curr=(node*)malloc(sizeof(node));
    curr->ch=ch;
    curr->next=NULL;
    if(st->top==NULL)
    {
        st->top=curr;
        printf("Push successfully!...\n");
    }
    else
    {
        curr->next=st->top;
        st->top=curr;
        printf("Push  Successfully...\n");
    }
}
char pop_stack(stack *st)
{   
    char pop_val;
    node *temp=st->top;
    if(st->top==NULL)
    {
        printf("Stack is empty..");
        exit(0);
    }
    else
    {
        pop_val=st->top->ch;
        st->top=st->top->next;
        free(temp);
    }
    return pop_val;
    
}
int main()
{
    stack st;
    char str[20],ch;
    init(&st);
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
        push_stack(&st,str[i]);
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