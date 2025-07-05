#include <stdio.h>
#include <stdlib.h>
typedef struct double_linked_list
{
    struct double_linked_list *prev;
    int data;
    struct double_linked_list *next;
} dll;
dll *traverse_dll(dll *la)
{
    dll *prev = NULL;
    while (la != NULL)
    {
        prev = la;
        la = la->next;
    }
    return prev;
}
dll *create_dll(dll **list1, int info)
{
    dll *curr, *last;

    curr = (dll *)malloc(sizeof(dll));
    curr->prev = NULL;
    curr->data = info;
    curr->next = NULL;
    if (*list1 == NULL)
    {
        *list1 = curr;
    }
    else
    {
        last = traverse_dll(*list1);
        curr->prev = last;
        last->next = curr;
        return last->next;
    }
}
void display_forward(dll *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);

        node = node->next;
    }
    printf("NULL\n");
}
void display_backward(dll *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->prev;
    }
    printf("NULL\n");
}
void insert_any(dll **list, int val, int po)
{
    dll *curr, *temp = *list, *temp1;
    curr = (dll *)malloc(sizeof(dll));
    int count = 1;
    curr->data = val;
    if (po == 1)
    {
        curr->prev = NULL;
        curr->next = *list;
        (*list)->prev = curr;
        *list = curr;
        return;
    }
    while (count != po && temp != NULL)
    {
        temp1 = temp;
        temp = temp->next;
        count = count + 1;
    }
    if (po == count)
    {
        curr->prev = temp1;
        curr->next = temp1->next;
        temp1->next = curr;
        curr->next->prev = curr;
    }
}
int main()
{
    dll *list = NULL, *last1;
    int node, num, po;
    printf("How many node do you want to create- ");
    scanf("%d", &node);
    for (int i = 0; i < node; i++)
    {
        int info;
        printf("Enter data: ");
        scanf("%d", &info);
        last1 = create_dll(&list, info);
    }

    display_forward(list);
    display_backward(last1);
    printf("Enter the number & position - ");
    scanf("%d%d", &num, &po);
    insert_any(&list, num, po);
    display_forward(list);
    display_backward(last1);
    return 0;
}
