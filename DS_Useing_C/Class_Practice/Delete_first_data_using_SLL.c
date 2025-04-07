#include <stdio.h>
#include <stdlib.h>

typedef struct single_linked_list
{
    int data;
    struct single_linked_list *next;
}SLL;

SLL *traverse_sll (SLL *list)
{
    SLL *prev=NULL;
    while(list!=NULL)
    {
        prev=list;
        list=list->next;
    }
    return prev;
}
void display_sll(SLL *list1)
{
    while(list1)
    {
        printf("%d -> ", list1->data);
        list1=list1->next;
    }
    printf("NULL\n");
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
void DeleteFirst(SLL **first)
{
    if(*first==NULL){
        printf("List is empty");
        exit(1);
    }
    SLL *temp=NULL;
    temp=(*first);
    (*first)=(*first)->next;
    free(temp);
}
int main()
{
    SLL *list1=NULL;
    char ch;
    do
    {
        create_sll(&list1);
        printf("\nDo you want to continue(y/n)-");
        fflush(stdin);
        getc(stdin);
        scanf("%c",&ch);
    } while((ch=='y')||(ch=='Y'));
        printf("Display the list-\n");
        display_sll(list1);
        DeleteFirst(&list1);
        printf("Display the new list after deletion of first- \n");
        display_sll(list1);
        return 0;
    }
