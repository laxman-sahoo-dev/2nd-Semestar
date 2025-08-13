    #include<stdio.h>
    #include <stdlib.h>
    typedef struct nodetype{
        int info;
        struct nodetype *next;
    }node;
    typedef struct stacktype{
        node *top;
        char ch;
    }stack;
    void initstack(stack *sorce,stack *inter,stack *dest)
    {
        sorce->top=NULL;
        inter->top=NULL;
        dest->top=NULL;
        sorce->ch='A';
        inter->ch='B';
        dest->ch='C';
    }
    void push(stack *st,int data)
    {
        node *curr;
        curr=(node*)malloc(sizeof(node));
        curr->info=data;
        curr->next=NULL;
        if(st->top==NULL)
        {
            st->top=curr;
        }
        else
        {
            curr->next=st->top;
            st->top=curr;
        }
    }
        
    int pop(stack *st)
    {
        node *temp=st->top;
        int pop_val;
        if(st->top==NULL)
        {
            printf("Stack is empty");
            exit(0);
        }
        pop_val=st->top->info;
        st->top=st->top->next;
        free(temp);
        return pop_val;
    }
    void move(int n, stack *source, stack *auxiliary, stack *target) {
        if (n > 0) {
            move(n - 1, source, target, auxiliary);
            int val = pop(source);
            push(target, val);
            printf("Move disk %d from %c to %c\n", val, source->ch, target->ch);
            move(n - 1, auxiliary, source, target);
        }
    }
    void display(node *n)
    {   
        while (n!=NULL)
        {
            printf("%d-> ",n->info);
            n=n->next;
        }
        printf("NULL\n\n");
    }
    int main()
    {
        int n=3;
        stack a,b,c;
        char A,B,C;
        initstack(&a,&b,&c);
        push(&a,14);
        push(&a,10);
        push(&a,6);
        display(a.top);
        move(3,&a,&b,&c);
        printf("After: ");
        display(c.top);
    }