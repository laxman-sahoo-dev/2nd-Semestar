
#include <stdio.h>
#include <stdlib.h>

typedef struct merge_link_list
{
    int data;
    struct merge_link_list *next;
} mll;
void create(mll **);
void merge(mll *, mll *, mll **);
void display(mll *);
mll *traverse_sll(mll *);
int main()
{
    mll *list1 = NULL, *list2 = NULL, *list3=NULL;
    printf("enter data for first link list-\n ");
    create(&list1);
    printf("enter data for second link list-\n ");
    create(&list2);
    merge(list1, list2,&list3);
    printf("Display the node1=\n");
    display(list1);
    printf("Display th node2=\n");
    display(list2);
    printf("Display after merge node1&node2= \n");
    display(list3);
    return 0;
}
mll *traverse_sll(mll *list)
{
    mll *prev = NULL;
    while (list != NULL)
    {
        prev = list;
        list = list->next;
    }
    return prev;
}
void create(mll **list)
{
    int item;
    char ch;

    do
    {
        printf("Enter data: ");
        scanf("%d", &item);

        mll *newNode = (mll *)malloc(sizeof(mll));
        if (!newNode)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        newNode->data = item;
        newNode->next = NULL;

        if (*list == NULL)
        {
            *list = newNode;
        }
        else
        {
            mll *last = traverse_sll(*list);
            last->next = newNode;
        }

        printf("Add another node? (Y/N): ");
        scanf(" %c", &ch);

    } while (ch == 'Y' || ch == 'y');
}

void merge(mll *n1, mll *n2, mll **n3)
{
    mll *tail=NULL;
    while (n1!=NULL)
    {
        mll *newnode=(mll*)malloc(sizeof(mll));
        newnode->data=n1->data;
        newnode->next=NULL;
        if((*n3)==NULL)
        {
            tail=newnode;
            (*n3)=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        n1=n1->next;
    }
    while (n2!=NULL)
    {
        mll *newnode=(mll*)malloc(sizeof(mll));
        newnode->data=n2->data;
        newnode->next=NULL;
        if((*n3)==NULL)
        {
            tail=newnode;
            (*n3)=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        n2=n2->next;
    }
    
}
void display(mll *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
