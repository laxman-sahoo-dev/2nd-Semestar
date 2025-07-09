#include <stdio.h>
#include <stdlib.h>

typedef struct linear_queue
{
    int info;
    struct linear_queue *next;
}lqueue;

lqueue *front=NULL,*rear=NULL;

void insert_queue(int data)
{
    lqueue *curr;
    curr=(lqueue*)malloc(sizeof(lqueue));
    curr->info=data;
    curr->next=NULL;
    if(rear==NULL)
    {
        rear=front=curr;
        printf("Insertion Sucessfull....\n");
        return;
    }
    rear->next=curr;
    rear=curr;
    printf("Insertion Sucessfull..\n");
}

int delete_queue()
{   
    lqueue *temp=front;
    if(front==NULL)
    {
        printf("Queue is empty!!\n");
    }
    front=front->next;
    if(front==NULL)
    {
        front=rear=NULL;
    }
    return temp->info;
}

void display()
{
    lqueue *temp;
    temp=front;
    while (temp)
    {
        printf("%d\n",temp->info);
        temp=temp->next;
    }
}

int main()
{
    int num,op;
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
                insert_queue(num);
                break;
            case 2:
                num=delete_queue();
                printf("Delete data = %d\n",num);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Option\n");
        }
    }
    
} 