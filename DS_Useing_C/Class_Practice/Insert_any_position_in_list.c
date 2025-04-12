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
void insert_any(SLL **list,int val,int po)
{
    SLL *node=NULL;
    SLL *prev=NULL;
    SLL *temp=NULL;
    node=(SLL *)malloc(sizeof(SLL));
    if(node==NULL){
        printf("Node creation filed!!!\n");
        exit(1);
    }
    node->data=val;
    node->next=NULL;
    if((*list)==NULL)
    {
        (*list)=node;
    }
    if(po==1)
    {
        node->next=(*list);
        (*list)=node;
        return;
    }
    int count=1;
    temp=(*list);
    //This loop trverse from initial list to the position where the data inserted
    while(count!=po&&temp->next!=NULL)
    {  
        prev=temp;//store the position-1 linked list adress
        temp=temp->next;
        count=count+1;//This check the right position where list insert
    }
    if(count==po)
    {
        node->next=prev->next;
        prev->next=node;
    }
    if(count+1==po){ //this is for last insert
        temp->next=node;
        node->next=NULL;
    }
    
}
int main()
{
    SLL *list1=NULL;
    char ch='y';
    int pos,new_data;
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
        printf("Enter the new data & position to insert: ");
        scanf("%d%d",&new_data,&pos);
        insert_any(&list1,new_data,pos);
        printf("Display the new list:\n");
        display_sll(list1);
        return 0;
    }
