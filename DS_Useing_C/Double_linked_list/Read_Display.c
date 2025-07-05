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
int main()
{
    dll *list = NULL, *last1;
    int node;
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
    return 0;
}
