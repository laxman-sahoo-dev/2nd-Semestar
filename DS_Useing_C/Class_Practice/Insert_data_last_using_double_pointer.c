#include <stdio.h>
#include <stdlib.h>

typedef struct single_linked_list
{
    int data;
    struct single_linked_list *next;
}SLL;

SLL *traverse_sll (SLL *list)
{  //always travese from begin to last link list
    SLL *prev=NULL;
    while(list!=NULL)
    {
        prev=list;
        list=list->next;
    }
    return prev;
    //always return the base adress of preveuse node of last node
}
void display_sll(SLL *list1)
{
    while(list1)
    {
        printf("%d\n", list1->data);
        list1=list1->next;
    }
}
void create_sll(SLL **list1)
{
    int item;
    SLL *node1=NULL; 
    SLL *last=NULL;
    printf("Please enter the data-");
    scanf("%d",&item);
    node1 = (SLL*)malloc(sizeof (SLL));
    if(node1==NULL)
    {
        printf("\n Node creation failed");
        return;
    }
    node1->data=item;
    node1->next=NULL;
    if((*list1)==NULL)//list not existing
    {
        (*list1)=node1;
    }
    else
    {
        last =traverse_sll(*list1);
        last->next=node1;   
    }
}
void insert_last(SLL **list1,int data1)
{
    SLL *node1=NULL;
    SLL *last_node=NULL;
    node1=(SLL*)malloc(sizeof(SLL));
     if(node1==NULL)
    {
        printf("\n Node creation failed");
        return;
    }
    node1->data=data1;
    node1->next=NULL;
    if((*list1)==NULL)//list not existing
    {
        (*list1)=node1;
        //store the first node adress
    }
    else
    {
        last_node=traverse_sll(*list1);
        last_node->next=node1;
    }
}
int main()
{
    SLL *list1=NULL;
    char ch='y';
    int num;
    while((ch=='y')||(ch=='Y'))
    {
        create_sll(&list1);
        printf("\nDo you want to continue(y/n)-");
        fflush(stdin);
        getc(stdin);
        scanf("%c",&ch);
    }
        printf("Display the list-\n");
        display_sll(list1);
        printf("Enter the new data to store at last position-");
        scanf("%d",&num);
        insert_last(&list1,num);
        printf("\nDisplay the new list- \n");
        display_sll(list1);
        return 0;
    }
