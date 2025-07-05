#include <stdio.h>
#include <stdlib.h>
typedef struct double_linked_list
{
    struct double_linked_list *prev;
    int data;
    struct double_linked_list *next;
} dll;
dll *traverse(dll *node)
{
    dll *prev;
    while (node != NULL)
    {
        prev = node;
        node = node->next;
    }
    return prev;
}
dll *create_dll(dll **list1)
{
    dll *curr, *last;
    curr = (dll *)malloc(sizeof(dll));
    printf("Enter Data- ");
    scanf("%d", &curr->data);
    curr->prev = NULL;
    curr->next = NULL;
    if (*list1 == NULL)
    {
        *list1 = curr;
    }
    else
    {
        last = traverse(*list1);
        last->next = curr;
        curr->prev = last;
    }
    return curr;
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
void delete_any(dll *list1, int po)
{
    dll *temp = list1, *pre = NULL;
    int count = 1;
    if (po == 1)
    {
        temp->next = NULL;
        return;
    }

    while (po != count && temp != NULL)
    {
        pre = temp;
        count = count + 1;
        temp = temp->next;
    }
    if (po == count)
    {
        pre->next = temp->next;
        temp->next->prev = pre;
        free(pre);
    }
}
int main()
{
    dll *list = NULL, *last = NULL;
    char ch;
    int po;
    do
    {
        last = create_dll(&list);
        getchar();
        printf("Do you want to continue- ");
        scanf("%c", &ch);
        fflush(stdin);
    } while (ch == 'y' || ch == 'Y');
    display_forward(list);
    display_backward(last);
    printf("Enter the position do want to  delete = ");
    scanf("%d", &po);
    delete_any(list, po);
    display_forward(list);
    display_backward(last);
}