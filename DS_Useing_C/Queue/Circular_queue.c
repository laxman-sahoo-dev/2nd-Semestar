#include <stdio.h>
#include <stdlib.h>
typedef struct circular_queue
{
    int info;
    struct circular_queue *next;
} cqueue;
cqueue *front = NULL, *rear = NULL;
void insert_queue(int data)
{
    cqueue *curr;
    curr = (cqueue *)malloc(sizeof(cqueue));
    curr->info = data;
    curr->next = NULL;
    if (rear == NULL)
    {
        rear = front = curr;
        rear->next = front;
        printf("Insertion successfull\n");
        return;
    }
    curr->next = front;
    rear->next = curr;
    rear = curr;
    printf("Insrtion successfull..\n");
}
int delete_queue()
{
    cqueue *temp;
    int data;
    temp = front;
    data = temp->info;
    if (rear == front)
    {
        rear = front = NULL;
        free(temp);
        printf("Insert from first Queue is empty\n");
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
    return data;
}
void display()
{
    cqueue *temp = front;
    if(temp==NULL)
    {
        printf("Queue is empty..\n");
        return;
    }
    do
    {
        printf("%d\n", temp->info);
        temp = temp->next;
    } while (temp != front);
}
int main()
{
    int num, op;
    printf("\tQueue Menu\t");
    printf("\n1-Insert- \n2=Delete\n3-Traverse\n4-Quit-\n");

    while (1)
    {
        printf("Enter Option- ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter the data to push- ");
            scanf("%d", &num);
            insert_queue(num);
            break;
        case 2:
            num = delete_queue();
            printf("Delete data = %d\n", num);
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