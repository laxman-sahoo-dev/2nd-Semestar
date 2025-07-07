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
    printf("Insertion Sucessfull..");
}
void delete_queue(queue *qu)
{
    
}
int main()
{

} 