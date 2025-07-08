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

void insert_queue(queue *qu , int val)
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
int delete_queue(queue *qu)
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
    int num,op;
    init_queue(&qu);
    
        printf("\tQueue Menu\t");
        printf("\n1-Insert- \n2=Delete\n3-Traverse\n4-Quit-\n");
        
    while (1)
    {
        printf("Enter Option- ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Enter the data to push- ");
                scanf("%d",&num);
                insert_queue(&qu,num);
                break;
            case 2:
                num=delete_queue(&qu);
                break;
            case 3:
                traverse_queue(&qu);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Option");
        }
    }
    
} 