#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int info;
    struct nodetype *next;
}node;

typedef struct queuetype
{
    node *front;
    node *rear;
}queue;

void init_queue(queue *qu)
{
    qu->front=qu->rear=NULL;
}
void insert_front(queue *qu,int val)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->info=val;
    temp->next=NULL;
    if(qu->front==NULL)
    {
        qu->rear=temp;
        qu->front=temp;
    }
    else
    {
        temp->next=qu->front;
        qu->front=temp;
    }
    
}
void insert_rear(queue *qu , int val)
{
    node *new_node=NULL;
    new_node=(node*)malloc(sizeof(node));
    if(new_node==NULL)
    {
        printf("Memory allocation is failed ");
        exit(0);
    }
    new_node->info=val;
    new_node->next=NULL;
    if(qu->rear==NULL)
    {
        qu->front=qu->rear=new_node;
        printf("Insertion Sucessfull...\n");
        return;
    }
    qu->rear->next=new_node;
    qu->rear=new_node;
    printf("Insertion Sucessfull..\n");
}
int delete_front(queue *qu)
{
    int popval=0;
    node *temp=qu->front;
    if(qu->front==NULL)
    {
        printf("Linked queue is empty..\n");
        exit(1);
    }
    else
    {
        popval=temp->info;
        qu->front=qu->front->next;
        free(temp);
    }
    if(qu->front==NULL)
    {
        qu->rear=NULL;
    }
    return popval;
}
int delete_rear(queue *qu)
{
    node *temp,*prev;
    int del_val;
    if(qu->front==NULL)
    {
        printf("queue is empty");
    }
    temp=qu->front;
    prev=NULL;
    while(temp->next)
    {
        prev=temp;
        temp=temp->next;
    }
    del_val=temp->info;
    qu->rear=prev;
    if(prev!=NULL)
    {
        prev->next=temp->next;
        free(temp);
    }
    if(qu->rear==NULL)
    {
        qu->front=NULL;
        free(temp);
    }
    return del_val;
}
int traverse_queue(queue *qu)
{
    node *temp=qu->front;
    if(qu->front==NULL)
    {
        printf("Linear Queue is empty");
    }
    temp=qu->front;
    printf("Linked list element are- \n");
    while(temp)
    {
        printf("%d\n",temp->info);
        temp=temp->next;
    }
}
int main()
{
    queue qu;
    int num,op,num1;
    init_queue(&qu);
    
        printf("\tQueue Menu\t");
        printf("\n1-Insert rear: \n 2-Insert front:\n3-Delete front:\n4-Delete rear:\n5-Traverse:\n6-Quit-\n");
        
    while (1)
    {
        printf("Enter Option- ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Enter the data to push rear end - ");
                scanf("%d",&num);
                insert_rear(&qu,num);
                break;
            case 2:
                printf("Enter the data to push front end - ");
                scanf("%d",&num);
                insert_front(&qu,num);
                break;
            case 3:
                num=delete_front(&qu);
                printf("Delete value from front - %d\n",num);
                break;
            case 4:
                num1=delete_rear(&qu);
                printf("Delrte value from rear- %d\n",num1);
            case 5:
                traverse_queue(&qu);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid Option");
        }
    }
    
} 