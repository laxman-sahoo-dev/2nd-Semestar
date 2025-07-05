#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial
{
    int coef;
    int exp;
    struct polynomial *next;
} poly;
poly *creat_list(poly *);
poly *add_poly(poly *, poly *);
void extra(poly *, poly *);
void display(poly *);
int main()
{
    poly *l1, *l2, *l3;
    char ch = '1';
    while (ch >= '1' && ch <= '3')
    {
        printf("1- create\n");
        printf("2 - Addition\n");
        printf("3 - Quit\n");
        printf("Enter a choice: ");
        fflush(stdin);
        scanf(" %c",&ch);
        switch (ch)
        {
        case '1':
            /* code */
            l1 = l2 = NULL;
            printf("Create the first list of polynomial - \n");
            l1 = creat_list(l1);
            printf("Create the second list of polynomial - \n");
            l2 = creat_list(l2);
            printf("Disply the first polynomial - ");
            display(l1);
            printf("\nDisply the second polynomial- \n");
            display(l2);
            break;
        case '2':
            l3 = NULL;
            printf("Addition of two polynomial = \n");
            l3 = add_poly(l1, l2);
            display(l1);
            display(l2);
            display(l3);
            break;
        case '3':
            exit(0);
            break;
        default:
            printf("Wrong Choice");
            break;
        }
    }
}
poly *creat_list(poly *f)
{
    poly *curr, *prev;
    char ch = 'y';
    while (ch == 'y')
    {
        curr = (poly *)malloc(sizeof(poly));
        if (curr == NULL)
        {
            printf("Memory allocation unsuccessfull");
            return 0;
        }
        curr->next = NULL;
        printf("Enter the cofficient - ");
        scanf("%d", &curr->coef);
        printf("Enter the exponent - ");
        scanf("%d", &curr->exp);
        if (f == NULL)
        {
            f = curr;
        }
        else
        {
            prev->next = curr;
        }
        prev = curr;
        printf("Do you want to continue : ");
        scanf(" %c", &ch);
    }
    return f;
}
void display(poly *ptr)
{
    while(ptr != NULL)
    {
    printf("%dx^%d ", ptr->coef, ptr->exp);
    ptr = ptr->next;
    if (ptr != NULL)
    {
        printf("+");
    }
    }
    printf("\n");
}
poly *add_poly(poly *l1, poly *l2)
{
    poly *curr, *prev, *p1, *p2, *p3 = NULL;
    p1 = l1;
    p2 = l2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->coef + p2->coef == 0)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        curr = (poly *)malloc(sizeof(poly));
        if (curr == NULL)
        {
            printf("Memory allocation is failed");
            return 0;
        }
        curr->next = NULL;
        if (p3 == NULL)
        {
            p3 = curr;
            prev = curr;
        }
        else
        {
            prev->next = curr;
            prev = curr;
        }
        
        if (p1->exp == p2->exp)
        {
            curr->coef = p1->coef + p2->coef;
            curr->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->exp < p2->exp)
        {
            curr->coef = p2->coef;
            curr->exp = p2->exp;
            p2 = p2->next;
        }
        else if(p1->exp > p2->exp)  
        {
            curr->coef = p1->coef;
            curr->exp = p1->exp;
            p1 = p1->next;
        }
    }
    if (p1 == NULL)
    {
        extra(prev, p2);
    }
    if (p2 == NULL)
    {
        extra(prev, p1);
    }
    return p3;
}
void extra(poly *prev, poly *p)
{
    poly *temp;
    while (p != NULL)
    {
        temp = (poly *)malloc(sizeof(poly));
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
        temp->coef = p->coef;
        temp->exp = p->exp;
        p = p->next;
    }
}