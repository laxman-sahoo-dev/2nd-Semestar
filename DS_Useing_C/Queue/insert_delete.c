#include <stdio.h>
#include <stdlib.h>
#define max 5
// Data structure for linear queue
typedef struct lquetype
{
    int arr[max];
    int front, rear;
} lqueue;
// function to initialise Linear queue

void init_LQ(lqueue *q)
{
    q->front = q->rear = -1;
}

// fuction to check queue Empty

int isempty_LQ(lqueue *lq)
{
    if (lq->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull_LQ(lqueue *lq)
{
    if (lq->rear == (max - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to insert an element into queue

void insert_LQ(lqueue *q, int val)
{
    if (isfull_LQ(q))
    {
        printf("\nLinear queue Full !!");
        exit(1);
    }
    if (q->front == -1) // if empty
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1);
    }
    q->arr[q->rear] = val;
}

// function to delete an element from queue

int delete_LQ(lqueue *q)
{
    int data;
    if (isempty_LQ(q))
    {
        printf("Queue is empty!\n!");
        exit(1);
    }
    data = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1);
    }
    return data;
}

// function to traverse queue

void traverse_queue(lqueue *q)
{
    // 'register' is a storage class specifier in C that suggests to the compiler
    // to store the variable in a CPU register for faster access.
    // However, modern compilers often ignore this suggestion.
    register int i = 0;
    if (isempty_LQ(q))
    {
        printf("\nLinear queue empty..");
        exit(0);
    }
    printf("\nLinear queue element are : \n");
    for (i = q->front; i <= q->rear; i++)
    {
        printf("%d\t", q->arr[i]);
    }
}
int main()
{
    lqueue lq;
    int choice, val;
    init_LQ(&lq);
    printf("\nMENU\n--------\n\
1-Insert element \n\
2-Delete element\n\
3-Traverse Linear queue\n\
4-Exit\n");
    while (1)
    {
        printf("\nEnter option-");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &val);
            insert_LQ(&lq, val);
            break;
        case 2:
            printf("Delete Element is = %d  ", delete_LQ(&lq));
            break;
        case 3:
            traverse_queue(&lq);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option!!");
        }
    }
}
