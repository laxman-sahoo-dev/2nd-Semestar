#include <stdlib.h>
#include <stdio.h>
typedef struct nodetype
{
    int info;
    struct nodetype *next;
} node;
typedef struct stacktype
{
    /* data */
    node *top;
} stack;
void initstack(stack *st)
{
    st->top=NULL;
}
void push(stack *st, int val)
{
    node *newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Memory overflow");
        return;
    }
    newnode->info = val;
    newnode->next = NULL;
    if (st->top == NULL)
    {
        st->top = newnode;
        printf("Stack Push Succrssfully");
    }
    else
    {
        newnode->next = st->top;
        st->top = newnode;
        printf("Stack push Sucrssfully");
    }
}
int pop(stack *st)
{
    int popval = 0;
    node *temp = st->top;
    if (st->top == NULL)
    {
        printf("Stack Empty..");
        exit(0);
    }
    else
    {
        popval = temp->info;
        st->top = st->top->next;
        free(temp);
    }
    return popval;
}

int main()
{
    stack st;
    int num,opt;
    int ;
}