//prority queue
#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int info,pr;
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

void insert_pq(queue *qu,int val,int pr)
{
    node *newnode=NULL,*temp;
    newnode = (node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("Memory Overflow\n");
        return;
    }
    newnode->info=val;
    newnode->pr=pr;
    newnode->next=NULL;
    if(qu->rear==NULL)
    {
        qu->front=qu->rear=newnode;
        printf("\nInsertion as first!!\n");
        return;
    }
    temp=qu->front;
    if(newnode->pr > temp->pr)
    {
        newnode->next=temp;
        qu->front=newnode;
        printf("\nInsertion at begin..");
        return;
    }
    while ((temp->next)&&newnode->pr<=temp->next->pr)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        temp->next=newnode;
        qu->rear=newnode;
        printf("\nInsert at end!!");
        return;
    }
    else if(newnode->pr > temp->next->pr)
    {
        newnode->next=temp->next;
        temp->next=newnode;
        printf("\nInsertion at middle!!");
    }
}
void display(queue *qu)
{
    node *temp=qu->front;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->info);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    queue qu;
    init_queue(&qu);
    insert_pq(&qu,12,10);
    insert_pq(&qu,20,5);
    insert_pq(&qu,78,11);
    insert_pq(&qu,66,3);
    insert_pq(&qu,44,7);
    display(&qu);
}