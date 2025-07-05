#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int info;
    struct nodetype *next;
} node;

typedef struct stacktype
{
    node *top;
} stack;

void initstack(stack *);
void push(stack *, int);
int pop(stack *);
void display(node *);
int main()
{
    stack st;
    int num, opt;
    initstack(&st);
    printf("%p!!",&st);
    do
    {
        printf("\nstack menu\n");
        printf("1- PUSH \n");
        printf("2-POP \n");
        printf("3- Quite\n");
        printf("4- Display");
        printf("Enter option - ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &num);
            push(&st, num);
            break;
        case 2:
            num = pop(&st);
            printf("%p??",&st);
            break;
        case 3:
            exit(0);
            break;
        case 4:
            printf("Display the stack:\n");
            display(st.top);
            break;
        default:
            printf("Invalid choice ");
        }
    } while (opt >= 1 && opt <= 4);
    return 0;
}

void initstack(stack *st)
{
    st->top = NULL;
}
void push(stack *st, int val)
{
    node *newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("memory allocation is failed");
        exit(0);
    }
    newnode->info = val;
    newnode->next = NULL;
    if (st->top == NULL)
    {
        st->top = newnode;
        printf("Stack push successfully\n");
    }
    else
    {
        newnode->next = st->top;
        st->top = newnode;
        printf("Stack push suvvessfully\n");
    }
}
int pop(stack *st)
{
    int popval = 0;
    node *temp = st->top;
    if (st->top == NULL)
    {
        printf("Stack is empty \n");
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
void display(node *nod)
{
    while (nod != NULL)
    {
        printf("%d -> ", nod->info);
        nod = nod->next;
    }
    printf("NULL\n");
}
