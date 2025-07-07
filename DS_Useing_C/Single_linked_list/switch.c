#include <stdio.h>
#include <stdlib.h>
typedef struct single_linked_list
{
    int data;
    struct single_linked_list *next;
} sll;

sll *traverse_sll(sll *node)
{
    sll *prev = NULL;
    while (node != NULL)
    {
        prev = node;
        node = node->next;
    }
    return prev;
}
void create(sll **list1, int val)
{
    sll *curr = NULL, *last;
    curr = (sll *)malloc(sizeof(sll));
    curr->data = val;
    curr->next = NULL;
    if ((*list1) == NULL)
    {
        (*list1) = curr;
    }
    else
    {
        last = traverse_sll(*list1);
        last->next = curr;
    }
}
void display(sll *node)
{
    while (node)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
void delete_element(sll **list, int num)
{
    sll *temp = (*list), *prev = NULL;
    if (temp->data == num)
    {
        (*list) = temp->next;
        free(temp);
    }
    else
    {
        while (temp->data != num)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
    }
}
void delete(sll **list2,int po)
{
    sll *prev=NULL,*temp=(*list2);
    if(po==1)
    {
        (*list2)=temp->next;
    }
    else
    {   
        int count=1;
        while(count!=po && temp!=NULL)
        {
            prev=temp;
            count = count + 1 ;
            temp=temp->next;
        }
        if(count==po)
        {
            prev->next=temp->next;
            free(temp);
        }
    }
}
void insert(sll **list1, int po)
{
    sll *temp = (*list1), *curr = NULL, *prev;
    int num;
    curr = (sll *)malloc(sizeof(sll));
    printf("Enter the insert value- ");
    scanf("%d", &num);
    curr->data = num;
    curr->next = NULL;
    if (po == 1)
    {
        (*list1) = curr;
        curr->next = temp;
        return;
    }
    else
    {
        int i = 1;
        while (po != i && temp != NULL)
        {
            prev = temp;
            i = i + 1;
            temp = temp->next;
        }
        if (po == i)
        {
            curr->next = temp;
            prev->next = curr;
        }
    }
}
int main()
{
    sll *list = NULL;
    int choice, val, po, num;

    printf("\n\tMENU\t\n");
    printf("1-Insert\n 2- Delete a given number- \n 3-Display\n 4- Insert any. \n5- Delete any.\n6-Exit\n");
    while (1)
    {
        printf("Enter a choice- ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value- ");
            scanf("%d", &val);
            create(&list, val);
            printf("\n!!%p\n",&list);
            break;
        case 2:
            printf("Enter the element to delete- ");
            scanf("%d", &num);
            delete_element(&list, num);
            break;
        case 3:
            printf("Display-\n");
            display(list);
            break;
        case 4:
            printf("Enter the position to insert-");
            scanf("%d", &po);
            insert(&list, po);
            break;
        case 5:
            printf("Delete data enter any position- ");
            scanf("%d", &po);
            delete(&list,po);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}